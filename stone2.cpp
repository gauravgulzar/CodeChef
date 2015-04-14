//
//  stone2.cpp
//  
//
//  Created by Gaurav Gulzar on 05/05/14.
//
//

#include <iostream>
using namespace std;

int maxInd(long int *a, int n){
    int i = 1;
    int max = 0;
    while(i++ < n){
        if(a[i] > a[max])
            max = i;
    }
    return max;
}

void diff(long int *a, int n, int v){
    for(int i=0; i<n; i++)
        a[i] = v-a[i];
}

int main(){
    int n,k;
    cin >> n >> k;
    long int a[n];
    for(int i=0; i<n; i++)
        scanf("%ld",&a[i]);
    while(k--){
        int t = maxInd(a,n);
        diff(a,n,a[t]);
    }
    
    for(int i=0; i<n; i++){
        if(i < n-1)
            printf("%ld ",a[i]);
        else
            printf("%ld",a[i]);
    }
    printf("\n");
    return 0;
}
