//
//  CodeDecode.cpp
//  
//
//  Created by Gaurav Gulzar on 09/12/13.
//
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <fstream>
#include <cstdlib>

#define TLEN 150000

int countArr[128];

int compare(const void *a, const void *b){
    int tmp = countArr[(int)(*(char*)a)] - countArr[(int)(*(char*)b)];
    if(tmp == 0){
        return (*(char*)a) - (*(char*)b);
    }
    else
        return tmp;
}

int main(){
    int T;
    cin >> T;
    char *cipher = new char[TLEN];
    while(T > 0){
        char fseq[27], waste[50]={'\0'};
        cin >> fseq;
        gets(waste);
        gets(cipher);
        int len = strlen(cipher);
        
        for(int i=0; i<128; i++)
            countArr[i] = 0;
        
        char cipherNew[len+1];
        
        int k = 0;
        
        for(int i=0; i<len; i++) {
            if(isalpha(cipher[i]))
                cipherNew[k++] = tolower(cipher[i]);
        }
        
        cipherNew[k] = '\0';
        
        for(int i=0; i<len; i++){
                countArr[(int)cipherNew[i]]++;
        }
        
        qsort(cipherNew,k,sizeof(char),compare);
        
        char map[128] = {'\0'};
        int j = 25;
        for(int i=k-1; i>=0; i--){
            if(map[(int)cipherNew[i]] == '\0'){
                map[(int)cipherNew[i]] = fseq[j];
                --j;
            }
        }
        
        char res[len+1];
        
        for(int i=0; i<len; i++){
            if(isalpha(cipher[i])) {
                if(isupper(cipher[i])) {
                    res[i] = toupper(map[(int)tolower(cipher[i])]);
                }
                else
                    res[i] = map[(int)cipher[i]];
            }
            else{
                res[i] = cipher[i];
            }
        }
        res[len] = '\0';
        
        cout << res << "\n"; 
        --T;
    }
}
