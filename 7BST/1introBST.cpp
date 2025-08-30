#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* insertBST(Node* root,int x){
    if(root==NULL) return new Node(x);
    if(root->data > x) root->left = insertBST(root->left,x);
    else root->right = insertBST(root->right,x); 
    return root; 
}

int main(){
    Node* root = NULL;
    root = insertBST(root,4);
    root = insertBST(root,10);
    root = insertBST(root,18);
    root = insertBST(root,3);
    root = insertBST(root,1);
    root = insertBST(root,8);
    root = insertBST(root,15);
    root = insertBST(root,81);
    root = insertBST(root,9);
    inorder(root);
    cout<<endl;

    return 0;
}