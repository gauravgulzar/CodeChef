//
//  BadNeigh.cpp
//  
//
//  Created by Gaurav Gulzar on 31/01/14.
//
//

#include <iostream>
using namespace std;

int maxFund(int *arr, int n){
    if(n==2)
        return max(arr[0],arr[1]);
    if(n==1)
        return arr[0];
    int a1[n-1],a2[n-1];
    a1[0] = arr[0];
    a1[1] = max(arr[0],arr[1]);
    for(int i=2; i<n-1; i++)
        a1[i] = max(a1[i-2]+arr[i],a1[i-1]);
    a2[0] = arr[1];
    a2[1] = max(arr[1],arr[2]);
    for(int i=2; i<n-1; i++)
        a2[i] = max(a2[i-2]+arr[i+1],a2[i-1]);
    
    return max(a1[n-2],a2[n-2]);
}

int main(){
    int arr[] = 	{162, 964, 975, 847, 31, 472, 61, 903, 713, 392, 798, 937, 378, 994, 969, 310, 924, 766, 529, 422, 786, 844, 746, 428, 332, 832, 280, 233, 609, 744, 165, 635, 335, 655, 414, 661, 686, 374, 739, 599};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxFund(arr,n) << "\n";
    return 0;
}
