//
//  chefeq.cpp
//  
//
//  Created by Gaurav Gulzar on 09/02/15.
//
//

#include <iostream>
using namespace std;

int main(){
    int t;
    int a[100000];
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int num = 0;
        for(int i=0; i<100000; i++)
            a[i] = 0;
        
        
        for(int i=0; i<n; i++){
            scanf("%d",&num);
            a[num] += 1;
        }
        
        int mrep = 1;
        for(int i=0; i<100; i++){
            if(a[i] > mrep)
                mrep = a[i];
        }
        
        cout << n-mrep << "\n";
    }
    return 0;
}
