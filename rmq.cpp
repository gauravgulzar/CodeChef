//
//  rmq.cpp
//  
//
//  Created by Gaurav Gulzar on 22/01/14.
//
//

#include <iostream>
using namespace std;

void initialize(int node, int b, int e, int *m, int *a, int n){
    if(b==e) {
        m[node] = b;
        return;
    }
    initialize(2*node, b, (b+e)/2, m,a,n);
    initialize(2*node+1,(b+e)/2 + 1, e,m,a,n);
    m[node] = (a[m[2*node]] <= a[m[2*node+1]]) ? m[2*node] : m[2*node+1];
}

int query(int node,int b, int e, int *m, int *a, int i, int j) {
    if(i>e || j<b)
        return -1;
    if(i<=b && j>=e)
        return m[node];
    int p1 = query(2*node,b,(b+e)/2,m,a,i,j);
    int p2 = query(2*node+1,(b+e)/2+1,e,m,a,i,j);
    
    if(p1 == -1)
        return m[node] = p2;
    if(p2 == -1)
        return m[node] = p1;
    if(a[p1] <= a[p2])
        return m[node] = p1;
    return m[node] = p2;
}

int main() {
    int a[] = {2,4,3,1,6,7,8,9,1,7};
    int n = sizeof(a)/sizeof(a[0]);
    int m[32];
    for(int i=0; i<32; i++)
        m[i] = -1;
    initialize(1,0,n-1,m,a,n);
    for(int i=0; i<32; i++)
        cout << m[i] << " ";
    cout << "\n";
    cout << query(1,0,n-1,m,a,2,6) << "\n";
}
