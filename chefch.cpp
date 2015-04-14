//
//  chefch.cpp
//  
//
//  Created by Gaurav Gulzar on 08/02/15.
//
//

#include <iostream>
using namespace std;

int main(){
    bool a[100000];
    //char waste[50];
    int t;
    scanf("%d\n",&t);
    //fgets(waste,50,stdin);
    while(t--) {
        char ch='\n';
        int n=0;
        while((ch=getchar()) != '\n' && ch != '\0'){
            a[n++] = ch == '+' ? true : false;
        }
        /*
        for(int i=0; i<n; i++)
            cout << a[i];
        cout << "\n";
        */
        int c = 0, j=0;
        bool prev = a[j];
        for(j = 1; j<n; j++){
            if(a[j] == prev)
                ++c;
            prev = !prev;
        }
        cout << c << "\n";
    }
    return 0;
}
