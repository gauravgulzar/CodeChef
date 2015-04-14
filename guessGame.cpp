//
//  guessGame.cpp
//  
//
//  Created by Gaurav Gulzar on 21/01/14.
//
//

#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        char op;
        int val,k;
        char rep[4];
        int lb = 1, ub = 1000000000;
        scanf("%d",&k);
        //scanf("%c%d%s",&op,&val,rep);
        cin >> op;
        cin >> val;
        cin >> rep;
        if(op == '<'){
            if(*rep == 'Y')
                ub = val-1;
            else
                lb = val;
        }
        else if(op == '>'){
            if(*rep == 'Y')
                lb = val+1;
            else
                ub = val;
        }
        else
            lb = ub = val;
        int l = 0;
        char w[50];
        fgets(w,50,stdin);
        assert(lb >= 1 && ub >=  1);
        //cout << lb << ub  << "\n";
        for(int i=1; i<k; i++){
            //cout << "Here\n";
            //scanf("%c %d %s",&op,&val,rep);
            cin >> op;
            cin >> val;
            cin >> rep;
            //cout << op<<val<<rep<<"\n";
            fgets(w,50,stdin);
            int ne = 0;
            if(op == '<'){//cout << "here1\n";
                if(*rep == 'Y')
                    val = val-1;
            }
            else if(op == '>'){
                if(*rep == 'Y')
                    val = val+1;
                    //cout << "here2\n";
            }
            else{
                if(*rep == 'Y')
                    if(val < lb || val > ub)
                        ++l;
                    else
                        lb = ub = val;
                else if(val >= lb && val <= ub)
                    ++l;
                ne = 1;
            }
            if(ne==0)
                if(val < lb || val > ub)
                    l++;
        }
        
        printf("%d\n",l);
    }
}
