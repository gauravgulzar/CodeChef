//
//  Error.cpp
//  
//
//  Created by Gaurav Gulzar on 17/01/14.
//
//

#include <iostream>
using namespace std;
int f[4] = {0,0,0,1};

int search(char *s, int n, char *p) {
    int i=0, j=0;
    for(;;) {
        if(i == n)
            return 0;
        if(s[i] == p[j]){
            i++;
            j++;
            if(j == 3)
                return 1;		
        }
        else {
            if(j > 0)
                j = f[j];
            else
                i++;
        }
    }
}

int main() {
    int T;
    cin >> T;
    char s[100000];
    char waste[50], ch;
    char p1[] = {'0','1','0'};
    char p2[] = {'1','0','1'};
    int n;
    fgets(waste,50,stdin);
    while(T--){
        n = 0;
        ch = '\0';
        while((ch = getchar()) != '\n')
            s[n++] = ch;
        
        if(search(s,n,p1) || search(s,n,p2))
           cout << "Good\n";
        else
           cout << "Bad\n";
    }
    return 0;
}
