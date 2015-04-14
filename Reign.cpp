//
//  Reign.cpp
//  
//
//  Created by Gaurav Gulzar on 12/12/13.
//
//

#include <iostream>
using namespace std;
#include <math.h>
#define MIN_INT -(pow(2,sizeof(int))-1)


int findMaxSum(long long int *a, int s, int e){
    int contigS = a[s], maxv = a[s];
    for(int i=s+1; i<=e; i++){
        if(a[i] > a[i] + contigS){
            contigS = a[i];
        }
        else
            contigS = a[i] + contigS;
        
        if(maxv < contigS)
            maxv = contigS;
    }
    
    //cout << s << "  " << e << "\n";
    return maxv;
}

int main(){
    int t;
    cin >> t;
    while(t > 0){
        int n,k;
        cin >> n;
        cin >> k;
        
        long long int a[n];
        for(int i=0; i<n; i++)
            cin >> a[i];
        
        int res = MIN_INT;
        
        //cout << findMaxSum(a,0,n-1) << "\n";
        int t1,t2;
        for(int i=0; i+k+1 < n; i++){
            if(( (t1 = findMaxSum(a,0,i)) + (t2 = findMaxSum(a,i+k+1,n-1)) ) > res)
                res = t1 + t2;
            
            //cout << t1 << "    " << t2 << "\n";
        }
        
        //t1 = findMaxSum(a,0,i+k)
        cout << res << "\n";
        
        --t;
    }
    return 0;
}
