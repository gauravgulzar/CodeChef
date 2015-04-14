//
//  winCount.cpp
//  
//
//  Created by Gaurav Gulzar on 20/05/14.
//
//

#include <iostream>
using namespace std;

int calcWin(int *m, int n, int maxn){
    int win[maxn],winc=0;
    win[0] = 0;
    for(int i=1;i<maxn; i++){
        win[i] = 0;
        for(int j=0; j<n && i-m[j] >=0; j++){
            if(win[i-m[j]] == 0){
                win[i] = 1;
                break;
            }
        }
        if(win[i] == 0)
            ++winc;
    }
    return winc;
}

int main(){
    int m[] = {2,4,7,11,20};
    int maxn = 6543;
    cout << calcWin(m,sizeof(m)/sizeof(m[0]),maxn) << "\n";
    return 0;
}
