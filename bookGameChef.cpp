//
//  bookGameChef.cpp
//  
//
//  Created by Gaurav Gulzar on 19/05/14.
//
//

#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b){
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

int main(){
    long long int p[19];
    p[0] = 1;
    for(int i=1; i<19; i++)
        p[i] = p[i-1]*10;
    
    long long int d[19];
    d[0] = 0;
    for(int i=1; i<19; i++)
        d[i] = d[i-1] + p[i-1]*9*i;
    
    int t;
    long long int n,nc;
    cin >> t;
    while(t--){
        scanf("%lld",&n);
        nc = n;
        int digit=0;
        while(nc>0){
            digit++;
            nc /= 10;
        }
        
        long long int ds = 0;
        ds = d[digit-1];
        ds += ((n - p[digit-1]+1)*digit);
        long long int g = gcd(10*n,ds);
        printf("%lld/%lld\n",ds/g,(10*n)/g);
    }
}
