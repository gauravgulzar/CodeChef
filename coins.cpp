//
//  coins.cpp
//  
//
//  Created by Gaurav Gulzar on 27/01/14.
//
//

#include <iostream>
using namespace std;
#include <queue>
#define MAXN 1000000000
//int n[MAXN/2+1];
int main(){
    int val;
    while((scanf("%d",&val)) > 0){
        queue<int> q;
        int d=0;
        q.push(val);
        while(!(q.empty())){
            int tmp = q.front();
            if((tmp/2 + tmp/3 + tmp/4) > tmp){
                q.push(tmp/2);
                q.push(tmp/3);
                q.push(tmp/4);
            }
            else
                d+=tmp;
            q.pop();
        }
        printf("%d\n",d);
    }
}
