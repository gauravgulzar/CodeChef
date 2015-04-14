//
//  Cake1.cpp
//  
//
//  Created by Gaurav Gulzar on 19/01/14.
//
//

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int x1, x2, x3,x4,y1,y2,y3,y4;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;
        int a1 = (x2-x1) * (y2-y1);
        int a2 = (x4-x3) * (y4-y3);
        
        int c1 = max(0, min(x2,x4) - max(x1,x3));
        int c2 = max(0, min(y2,y4) - max(y1,y3));
        if(c1 * c2 > 0)
            cout << a1 + a2 - c1*c2 << "\n";
        else
            cout << a1+a2 << "\n";
    }
    return 0;
}
