#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vector< pair< int,int > > VPII
#include <algorithm>
#include <map>
#include <cstdio>
#include <vector>
int main()
{
    int n,m,p,i,j,ans;
    cin >> n >> m >> p;
    VPII ar;
    ar.resize(p);
    for(i=0; i<p; i++)
        cin >> ar[i].F >> ar[i].S;
    sort(ar.begin(),ar.end());
    j=0;
    for(i=1; i<=n; i++)
    {
        //process for i
        map < int, int > mymap;
        while(j<ar.size()  && ar[j].F==i)
        {
            // increase in map value of ar[j].S
            mymap[ar[j].S]++;
            // store in map, ar[j].S-1 and ar[j].S+1
            if(ar[j].S>1 && mymap.count(ar[j].S-1)==0)
                mymap[ar[j].S-1]=0;
            if(ar[j].S<m && mymap.count(ar[j].S+1)==0)
                mymap[ar[j].S+1]=0;
            j++;
        }
        // answer normally
        int ans=m-1;
        //traversing over map
        for(map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        {
            // no processing if j==m
            if(it->F==(m))continue;
            
            // j+1 is in map
            if(mymap.count(it->F+1)!=0)
            {
                // if (value at j+1) < (value at j)+1, our answer is -1
                if((it->F+it->S)>(mymap[it->F+1]+it->F+1)){ans=-1;break;}
                // else, add difference to ans. subtract 1.
                ans+=(mymap[it->F+1])-it->S;
            }
            else
            {
                // if (value at j+1) which will be j+1 < value at j ie. it->S, our answer is -1
                if(it->S>1){ans=-1;break;}
                // else, add difference to ans. subtract 1.
                ans+=it->S;
            }
        }
        // print answer
        cout << ans << endl;
    }
    return 0;
}