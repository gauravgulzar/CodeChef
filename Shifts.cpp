//
//  Shifts.cpp
//  
//
//  Created by Gaurav Gulzar on 28/12/13.
//
//

#include <iostream>
using namespace std;

struct Node{
    int val;
    int numg;
    Node *left;
    Node *right;
};

void insert(Node *root, int *c, int v){
    if(!root){
        root = new Node;
        root->val = v;
        root->numg = *c;
        root->left = root->right = NULL;        
        return;
    }
    
    if(v < root->val){
        *c += (root->numg + 1);
        insert(root->left,c,v);
    }
    
    else if(v > root->val){
        insert(root->right, c, v);
        root->numg +=1;
    }
    
    else {
        //*c += root->numg;
        root->numg = *c;
        if(root->left){
            root = root->left;
            while(root->right){
                root->numg += 1;
                root = root -> right;
                
            }
            root = root->right;
            root = new Node;
            root->val = v;
            root->numg = *c;
            root->left = root->right = NULL;
            
        }
        else{
            root->left = new Node;
            root = root->left;
            root->val = v;
            root->numg = *c;
            root->left = root->right = NULL;
        }
            
    }
}

int main(){
    int T;
    //cin >> T;
    //int res;
    //while(T > 0){
        int N;
        cin >> N;
        int a[N];
        for(int i=0; i<N; i++)
            cin >> a[i];
        Node *root = NULL;
        int res = 0,temp = 0;
        root = new Node;
        root->val = a[0];
        root->numg = 0;
        root->left = root->right = NULL;
        for(int i=1; i<N; i++){
            insert(root,&res,a[i]);
            temp += res;
            res = root->numg;
        }
        cout << temp << "\n";
        //--T
    //}
}


