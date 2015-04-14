//
//  chrl1.cpp
//  
//
//  Created by Gaurav Gulzar on 26/01/14.
//
//

#include <iostream>
using namespace std;
#include <cmath>
int main(){
    int t;
    cin >> t;
    int n,k;
    while(t--){
        cin >> n >> k;
        int a[2][n];
        for(int i=0; i<n; i++)
            cin >> a[0][i]>> a[1][i];
            
        int num = (int)pow(2.0,n) - 1;
        int maxw = 0;
        for(int i=1; i<=num; i++){
            int j=i, in = n-1, cost=k,temp=0;
            while(j>0){
                if(j & 1){
                        temp += a[1][in];
                        cost = cost - a[0][in];
                    }
                --in;
                j = j>>1;
            }
            if(cost>=0 && temp>maxw)
                maxw=temp;
        }
        cout << maxw << "\n";
    }
}