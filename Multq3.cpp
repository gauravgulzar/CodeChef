//
//  Multq3.c
//  
//
//  Created by Gaurav Gulzar on 12/12/13.
//
//

#include <iostream>
using namespace std;

inline void fastRead(int *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

int main() {
    int n,q;
    int c,s,e;
    //scanf("%d %d",&n,&q);
    fastRead(&n);
    fastRead(&q);
    int a[n];
    int i=0;
    for(i=0; i<n;i++)
        a[i] = 0;
    
    while(q > 0){
        //scanf("%d %d %d",&c,&s,&e);
        fastRead(&c);
        fastRead(&s);
        fastRead(&e);
        if(c == 0){
            int i;
            for(i=s; i<=e; i++){
                a[i]++;
            }
        }
        else {
            int i;
            int count = 0;
            for(i=s; i<=e; i++){
                if(a[i] % 3 == 0)
                    count++;
            }
            printf("%d\n",count);
        }
        --q;
    }
}
