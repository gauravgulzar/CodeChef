//
//  Roxor.cpp
//  
//
//  Created by Gaurav Gulzar on 23/05/14.
//
//

#include <iostream>
using namespace std;

int move[3];
bool win(int *a, int n){
    for(int i=0; i<n-1; i++){
        if(a[i] > 0){
            a[i] -= 1;
            for(int j=i+1;j<n;j++){
                a[j] += 1;
                for(int k=j; k<n; k++){
                    a[k] += 1;
                    if(!win(a,n)){
                        a[j] -= 1;
                        a[k] -= 1;
                        a[i] += 1;
                        move[0] = i; move[1] = j; move[2] = k;
                        return true;
                    }
                    a[k] -= 1;
                }
                a[j] -= 1;
            }
            a[i] += 1;
        }
    }
    return false;
}

int main(){
    int a[] = {0, 0, 1, 0, 1, 100};
    int n = sizeof(a)/sizeof(a[0]);
    if(win(a,n))
        cout << move[0] << " " << move[1] << " " << move[2] << "\n";
    else
        cout << "No move\n";
}
