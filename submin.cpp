//
//  submin.cpp
//  
//
//  Created by Gaurav Gulzar on 08/02/14.
//
//

#include <iostream>
using namespace std;
#include <cmath>
#include <cstdio>
int *a;
int *mn, n;
//int a[] = {2,4,3,1,6,7,8,9,1,7};
//int mn[32],mx[32];
void initialize(int node, int b, int e){
    if(b==e) {
        mn[node] = b;
        return;
    }
    initialize(2*node, b, (b+e)/2);
    initialize(2*node+1,(b+e)/2 + 1, e);
    mn[node] = ((a[mn[2*node]] <= a[mn[2*node+1]]) ? mn[2*node] : mn[2*node+1]);
}

int query_min(int node, int b, int e, int i, int j){
    if(i>e || j<b)
        return -1;
    
    if(i<=b && j>=e)
        return mn[node];
    
    int p1 = query_min(2*node,b,(b+e)/2,i,j);
    int p2 = query_min(2*node+1,(b+e)/2+1,e,i,j);
    
    if(p1==-1)
        return p2;
    if(p2==-1)
        return p1;
    if(a[p1]<=a[p2])
        return p1;
    return p2;
}

int main() {
    cin >> n;
    int t[n];
    for(int i=0; i<n; i++)
        scanf("%d",&t[i]);
    int l,r;
    a = t;
    int s = (int)(log10(n)/log10(2));
    s = 2*( int)(pow(2.0f,(s+1)));
    int t2[s];
    for(int i=0;i<s;i++)
        t2[i] = -1;
    mn = t2;
    initialize(1,0,n-1);
    int q;
    cin >> q;
    int k;
    while(q--){
        scanf("%d",&k);
        int r=0,ind;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                ind = query_min(1,0,n-1,i,j);
                if(ind >= 0 && a[ind] == k)
                    ++r;
            }
        }
        printf("%d\n",r);
    }
}
