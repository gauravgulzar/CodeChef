//
//  chefCake.cpp
//  
//
//  Created by Gaurav Gulzar on 18/05/14.
//
//

#include <iostream>
using namespace std;

int main(){
    int t,n;
    cin >> t;
    while(t--){
        scanf("%d",&n);
        char a1='n',a2='y',a3='n';
        if(n > 360){
            printf("n n n\n");
            continue;
        }
        if(n == 1){
            printf("y y y\n");
            continue;
        }
        
        if(360%n == 0)
            a1 = 'y';
        /*
        if(a1 == 'n'){
            if(360%(n-1) <= 1)
                a2 = 'n';
        }
        */
        int q = 360/(n-1);
        int r = 360%(n-1);
        
        if(n*(n+1)/2 <= 360)
            a3 = 'y';
        
        printf("%c %c %c\n",a1,a2,a3);
    }
}
