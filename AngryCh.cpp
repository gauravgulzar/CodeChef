//
//  AngryCh.cpp
//  
//
//  Created by Gaurav Gulzar on 19/01/14.
//
//

#include <iostream>
using namespace std;
#include <cmath>;
#include <cstdlib>;
#define MAX_INT 1000000000

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int unfair(int *a, int n, int k){
    qsort(a,n,sizeof(int),compare);
    //for(int i=0; i<n; i++) cout << a[i] << " ";
    //cout << "\n";
    int unf = (int)MAX_INT;
    for(int i=0; i+k-1 < n; i++){
        if((a[i+k-1] - a[i]) < unf)
            unf = a[i+k-1] - a[i];
    }
    return unf;
}
int main() {
    int n,k;
    cin >> n;
    cin >> k;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    cout << unfair(a,n,k);
    return 0;
}

