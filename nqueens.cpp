//
//  nqueens.cpp
//  
//
//  Created by Gaurav Gulzar on 13/05/14.
//
//

#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>
#define N 8
int res,a,b;
bool place(int *row, int n, int pos){
    for(int j=0; j<n; j++){
        if(row[j] != -1 && (row[j] == pos || abs(pos-row[j]) == abs(j-n)))
            return false;
    }
    return true;
}

bool print(int *row){
    //cout << ++res << "\n";
    if(row[a-1] != b-1)
        return false;
    cout << ++res << "\t";
    for(int i=0; i<N; i++)
        cout << row[i]+1 << " ";
    cout << "\n";
    return true;
}

bool nqueens(int *row, int rnum){
    if(rnum == N){
        return print(row);
    }
    
    for(int i=0; i<N; i++){
        if(place(row,rnum,i)){
            row[rnum] = i;
            nqueens(row,rnum+1);
        }
    }
    return true;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &a, &b);
        res = 0;
    //memset(x, 0, sizeof x); lineCounter = 0;
        int *row = new int[N];
        for(int i=0; i<N; i++)
            row[i] = -1;
        printf("SOLN\tCOLUMN\n");
        printf("# \t1 2 3 4 5 6 7 8\n\n");
        nqueens(row,0); // generate all possible 8! candidate solutions
        if (TC) printf("\n");
    }
    return 0;
}