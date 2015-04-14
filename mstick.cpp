//
//  mstick.cpp
//  
//
//  Created by Gaurav Gulzar on 22/01/14.
//
//

#include <iostream>
using namespace std;
#include <cmath>
#include <cstdio>
int *a;
int *mn,*mx, n;
//int a[] = {2,4,3,1,6,7,8,9,1,7};
//int mn[32],mx[32];
void initialize(int node, int b, int e){
    if(b==e) {
        mx[node] = b;
        mn[node] = b;
        return;
    }
    initialize(2*node, b, (b+e)/2);
    initialize(2*node+1,(b+e)/2 + 1, e);
    mn[node] = ((a[mn[2*node]] <= a[mn[2*node+1]]) ? mn[2*node] : mn[2*node+1]);
    mx[node] = (a[mx[2*node]] >= a[mx[2*node+1]]) ? mx[2*node] : mx[2*node+1];
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

int query_max(int node, int b, int e, int i, int j){
    if(i>e || j<b)
        return -1;
    
    if(i<=b && j>=e)
        return mx[node];
    int p1 = query_max(2*node,b,(b+e)/2,i,j);
    int p2 = query_max(2*node+1,(b+e)/2+1,e,i,j);
    
    if(p1 == -1)
        return p2;
    if(p2 == -1)
        return p1;
    if(a[p1]>=a[p2])
        return p1;
    return p2;
}

int main() {
    cin >> n;
    int t[n];
    for(int i=0; i<n; i++)
        scanf("%d",&t[i]);
    
    int q;
    cin >> q;
    int l,r;
    a = t;
    int s = (int)(log10(n)/log10(2));
    s = 2*( int)(pow(2.0f,(s+1)));
    int t2[s],t3[s];
    for(int i=0;i<s;i++)
        t2[i] = t3[i] = -1;
    mn = t2;
    mx = t3;
    initialize(1,0,n-1);
    for(int i=0; i<q; i++){
        scanf("%d %d",&l,&r);
        int v1 = query_min(1,0,n-1,l,r) ;
        int v2 = query_max(1,0,n-1,l,r);
        //cout << v1 <<v2<< "\n";
    
        int vr1 = query_max(1,0,n-1,0,l-1);
        int vr2 = query_max(1,0,n-1,r+1,n-1);
        int m;
        if(vr1>=0 && vr2>=0)
            m = (a[vr1] >= a[vr2]?a[vr1]:a[vr2]);
        else if(vr1<0)
            m = a[vr2];
        else if(vr2<0)
            m = a[vr1];
        //m = ((m+a[v1] >= a[v1]+(a[v2]-a[v1])/2.0)? m+a[v1] : a[v1]+(a[v2]-a[v1])/2.0);
        //printf("%.1lf\n",m);
        if(((a[v2]-a[v1])/2) >= m){
            if((a[v2]-a[v1])%2)
                printf("%d.5\n",a[v1]+(a[v2]-a[v1])/2);
            else
                printf("%d.0\n",a[v1]+(a[v2]-a[v1])/2);
        }
        else
            printf("%d.0\n",m+a[v1]);
    }
    return 0;
}
