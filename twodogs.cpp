//
//  twodogs.cpp
//  
//
//  Created by Gaurav Gulzar on 16/02/14.
//
//

#include <iostream>
using namespace std;

#define MAXL 6
#define MAXS 5
int map[MAXL][2];

int main() {
    for(int i=0; i<MAXL; i++)
        map[i][0] = map[i][1] = MAXS;
    
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++){
       if(map[a[i]][0] == MAXS)
           map[a[i]][0] = i+1;
    }
    
    for(int i=n-1; i>=0; i--){
        if(map[a[i]][1] == MAXS)
          map[a[i]][1] = n-i;
    }
    
    int res = MAXS;
    for(int i=0; i<n; i++){
        int first = map[a[i]][0];
        int rest = k - a[i];
        
        if(rest > 0 && a[i] != rest) {
            int t1 = map[rest][0];
            int t2 = map[rest][1];
            int temp = MAXS;
            if(t1 != MAXS && t2 != MAXS)
                 temp = min(t1,t2);
            if(temp != MAXS){
                int tres = max(first,temp);
                if(tres < res)
                    res = tres;
            }
        }
                  
    }
    if(res != MAXS)
       cout << res;
    else
       cout << "-1";
              
     return 0;
              
}
