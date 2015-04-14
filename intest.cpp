//
//  intest.cpp
//  
//
//  Created by Gaurav Gulzar on 20/01/14.
//
//

#include <iostream>
using namespace std;
#include <cstdlib>
#define gc getc_unlocked
int main() {
    int t,k;
    scanf("%d%d",&t, &k);
    register int res = 0;
    while(t--) {
        char c = gc(stdin);
        while(c < '0' || c > '9')
            c = gc(stdin);
        int n=0;
        while(c >='0' && c <='9'){
            n = ((n<<3)+(n<<1)) + (c - '0');
            c = gc(stdin);
        }
        if(n%k == 0)
            ++res;
    }
    
    cout << res;
    return 0;
}
