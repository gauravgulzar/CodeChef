//
//  TwoArrays.cpp
//  
//
//  Created by Gaurav Gulzar on 19/01/14.
//
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int compare(const void *a, const void *b){
    return *(int *)(a) - *(int *)(b);
}

int check(int *a1, int *a2, int n, int k){
    qsort(a1,n,sizeof(int),compare);
    qsort(a2,n,sizeof(int),compare);
    int i;
    for(i=0; i<n && a1[i] + a2[n-1-i] >= k; i++);
    if(i >= n)
        return 1;
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    int n,k;
    while(t--){
        cin >> n;
        cin >> k;
        int a1[n], a2[n];
        for(int i=0; i<n; i++)
            cin >> a1[i];
        
        for(int i=0; i<n; i++)
            cin >> a2[i];
        
        if(check(a1,a2,n,k))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
