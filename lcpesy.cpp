//
//  lcpesy.cpp
//  
//
//  Created by Gaurav Gulzar on 08/02/14.
//
//

#include <iostream>
using namespace std;
#include <cstring>
#define SIZE 10000
int main() {
    int t;
    cin>> t;
    char waste[50];
    fgets(waste,50,stdin);
    char A[SIZE+2], B[SIZE+2];
    while(t--){
        fgets(A,SIZE+2,stdin);
        fgets(B,SIZE+2,stdin);
        int m[128],res=0;
        for(int i=0; i<128; i++)
            m[i] = 0;
        
        //for(int i=0; i<128; i++)
          //  cout << m[i] << " ";
        //cout << "\n";
        
        for(int i=0; A[i] != '\n' && A[i] != '\0'; i++)
            ++m[A[i]];
        
        //for(int i=0; i<128; i++)
          //  cout << m[i] << " ";
        //cout << "\n";
        int l = strlen(B);
        for(int i=0; i<l ; i++){
            if(m[B[i]] > 0){
                ++res;
                --m[B[i]];
            }
        }
        printf("%d\n",res);
    }
}


