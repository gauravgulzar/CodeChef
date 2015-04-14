//
//  arrangeArr.cpp
//  
//
//  Created by Gaurav Gulzar on 18/05/14.
//
//

#include <iostream>
using namespace std;
#include <cstdlib>
int compare(const void *a, const void *b){
    long int * p1 = (long int *)a;
    long int * p2 = (long int *)b;
    if(*p1 < *p2)
        return -1;
    return 1;
}
int main(){
    long int *a = new long int[100000];
    int t;
    cin >> t;
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%ld",&a[i]);
        qsort(a,n,sizeof(long int),compare);
/*        for(int i=0; i<n; i++)
            printf("%ld ",a[i]);
        cout << "\n";
*/
        for(int i=0; i<=n-i-1; i++){
            if(i == n-i-1)
                printf("%ld",a[i]);
            else
                printf("%ld %ld ",a[i],a[n-1-i]);
        }
        
        printf("\n");
    }
}
