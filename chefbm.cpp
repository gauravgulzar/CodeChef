#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
struct loc {
    long int c;
	loc *next;
};

loc* newLoc(long int j){
    loc* l = new loc;
    l->c = j;
	l->next = NULL;
    return l;
}
/*
void initialize(long int *a,long int m){
    for(long int i=0; i<m; i++)
        a[i] = i+1;
}*/

int main(){
    long int n,m,p;
    cin >> n >> m >> p;
    loc **l = new loc*[100001];
	for(int i=0; i<p; i++)
		l[i] = NULL;
	
	while(p--){
        long int i,j;
        scanf("%ld %ld",&i,&j);
        loc *t = newLoc(j-1);
		t->next = l[i-1];
		l[i-1] = t;
    }
	
	long int *a = new long int[m];
	for(long int i=0; i<n; i++){
        loc* t = l[i];
        if(t == NULL){
            printf("%ld\n",m-1);
            continue;
        }
		map <int,int> m;
        while(t){
            m[t->c] ++;
            t = t->next;
        }
        
        for(map<int, int>::iterator i = m.begin(); i != m.end(); ++i){
            
        }
	}
	return 0;
}