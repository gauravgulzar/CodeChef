//
//  sumtrian.cpp
//  
//
//  Created by Gaurav Gulzar on 21/01/14.
//
//

#include <iostream>
using namespace std;

int main() {
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n][n];
        //for(int i=0; i<n; i++)
          //  a[i] = new int[i+1];
        for(int i=0; i<n; i++)
            for(int j=0; j<=i; j++)
                scanf("%d",&a[i][j]);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                int t = 0, tl = 0;
                if(j <= i-1)
                    t = a[i-1][j];
                if(j>0)
                    tl = a[i-1][j-1];
                a[i][j] = max(t,tl) + a[i][j];
            }
        }
        int max = 0;
        for(int j=0; j<n; j++)
            if(a[n-1][j] > max)
                max = a[n-1][j];
        
        cout << max << "\n";
    }
}
