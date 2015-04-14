//
//  Double.cpp
//  
//
//  Created by Gaurav Gulzar on 02/01/14.
//
//

#include <iostream>
using namespace std;
#include <cstdlib>


long long int scan_f() {
    long long int n = 0;
    char c;
    c = getchar_unlocked();
    while(c < '0' || c > '9')
        c = getchar_unlocked();
    while(c >='0' && c <= '9') {
        n = ((n>>3) + (n>>1)) + (c - '0');
        c = getchar_unlocked();
    }
    return n;
}

void print_f(long long int n){
    char buffer[11];
    int i=9;
    buffer[10] = '\n';
    
    do {
        buffer[i--] = n % 10 + '0';
        n = n/10;
    } while(n > 0);
    
    while(++i < 11){
        putchar_unlocked(buffer[i]);
    }
}

int main() {
    int T;
    long long int n;
    cin >> T;
    while(T--){
        n = scan_f();
        if(n % 2 == 0)
            print_f(n);
        else
            print_f(n-1);
        
        //putchar_unlocked('\n');
    }
    return 0;
}
