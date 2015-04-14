//
//  AlexNum.cpp
//  
//
//  Created by Gaurav Gulzar on 07/12/13.
//
//

#include <iostream>
using namespace std;

int compare(const void *a,const void *b){
    return (*(int*)(a) - *(int*)(b));
}

int main() {
    int T,N;
    cin >> T;
    if(T < 0 || T > 4){
        cout << 0;
        exit(0);
    }
    while(T > 0){
        cin >> N;
        if(N > 100000){
            cout << 0;
            exit(0);
        }
        long long int inp[N];
        for(int i=0; i<N; i++) {
            cin >> inp[i];
            if(inp[i] > 1000000000){
                cout << 0;
                exit(0);
            }
        }
        qsort(inp,N, sizeof(int), compare);
        int rep = 0, tmp = 1;
        
        for(int i=0; i<N; i++){
            int j = i+1;
            for(; j < N && inp[j] == inp[i]; j++)
                tmp++;
            if(j > i+1){
                rep += (tmp * (tmp-1)) / 2;
                tmp = 1;
                i = j-1;
            }
        }
        //if(rep > 0) {
            int res = ((N * (N-1)) / 2 ) - rep;
            cout << res << "\n";
        //}
        --T;
    }
    return 0;
}
