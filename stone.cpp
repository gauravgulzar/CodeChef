#include <iostream>
using namespace std;
#include <stdio.h>
int main(){
	int n,k;
	cin >> n >> k;
	long int a[n];
	int min,max;
	for(int i=0; i<n; i++)
        scanf("%ld",&a[i]);
    min = max = 0;
    for(int i=1; i<n; i++){
        if(a[i] > a[max])
            max = i;
        if(a[i] < a[min])
            min = i;
    }
	if(k > 0){
		int maxv;
		maxv = a[max];
		for(int i=0; i<n; i++)
			a[i] = maxv-a[i];
		if(k%2 == 0){
			maxv = a[min];
			for(int i=0; i<n; i++)
				a[i] = maxv-a[i];
		}
	}
    for(int i=0; i<n; i++) {
        printf("%ld\t",a[i]);
    }
    printf("\n");
    return 0;
}
