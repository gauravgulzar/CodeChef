//
//  CountShifts.cpp
//  
//
//  Created by Gaurav Gulzar on 07/01/14.
//
//

#include <iostream>
using namespace std;

struct Node {
    int data, rep, wt;
    Node *left, *right;
};

int insert(int v, Node **root) {
    if(!(*root)) {
        (*root) = new Node;
        (*root)->data = v;
        (*root)->rep = 1;
        (*root)->wt = 0;
        (*root)->left = (*root)->right = 0;
        return 0;
    }
    
    if(v < (*root)->data) {
        return insert(v, &((*root)->left)) + ((*root)->wt + (*root)->rep);
    }
    
    if(v > (*root)->data){
        (*root)->wt += 1;
        return insert(v, &((*root)->right));
    }
    
    else {
        (*root)->rep += 1;
        return (*root)->wt;
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int s;
        cin >> s;
        int arr[s];
        for(int i=0; i<s; i++)
            cin >> arr[i];
        int c = 0;
        Node *root = NULL;
        for(int i=0; i<7; i++){
            c += insert(arr[i], &root);
    }
        
        cout << c << "\n";
    }
    return 0;
}