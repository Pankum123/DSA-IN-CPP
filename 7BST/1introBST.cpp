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


int InorderPredecessor(Node* root,int n){
    Node* ptr = root;
    while(ptr && ptr->data != n) {
        if(ptr->data > n) ptr = ptr->left;
        else ptr = ptr->right;
    }
    if(ptr==NULL) return -1; // Not Found

    // Case 1: Left subtree exist
    if(ptr->left){
        Node* temp = ptr->left;
        while(temp->right) temp = temp->right;
        return temp->data;
    }
    
    // Case 2: No left subtree → go up to parent
    Node* predecessor = NULL;
    Node* ancestor = root;
    while(ancestor != ptr){
        if(ptr->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        }
        else{
            ancestor = ancestor->left;
        }
    }
    return predecessor ? predecessor->data : -1;
}

int InorderSuccessor(Node* root,int n){
    Node* ptr = root;
    while(ptr && ptr->data != n) {
        if(ptr->data > n) ptr = ptr->left;
        else ptr = ptr->right;
    }
    if(ptr==NULL) return -1; // Not Found

    // Case 1: Right subtree exist
    if(ptr->right){
        Node* temp = ptr->right;
        while(temp->left) temp = temp->left;
        return temp->data;
    }
    
    // Case 2: No right subtree → go up to parent
    Node* successor = NULL;
    Node* ancestor = root;
    while(ancestor != ptr){
        if(ptr->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else{
            ancestor = ancestor->right;
        }
    }
    return successor ? successor->data : -1;
}

void deleteBST(Node* root,int n){
    Node* prev = NULL;
    Node* temp = root;
    while(temp && temp->data != n){
        prev = temp;
        if(temp->data > n) temp = temp->left;
        else temp = temp->right;
    }

    // leaf Node
    if(!temp->left && !temp->right){
        if(prev->left==temp) prev->left = NULL;
        else prev->right = NULL;
    }

    // 1 child
    else if(!temp->left || !temp->right){
        if(prev->left==temp){
            if(temp->left) prev->left = temp->left;
            else prev->left = temp->right; 
        }
        else{
            if(temp->left) prev->right = temp->left;
            else prev->right = temp->right;
        }
    }
    // 2 child (internal node)
    else{
        Node* succ = temp->right;
        prev = temp;
        while(succ->left){
            prev = succ;
            succ = succ->left;
        } 
        temp->data = succ->data;
        // delete succ
        temp = succ;

        // leaf Node
        if(!temp->left && !temp->right){
            if(prev->left==temp) prev->left = NULL;
            else prev->right = NULL;
        }

        // 1 child
        else if(!temp->left || !temp->right){
            if(prev->left==temp){
                if(temp->left) prev->left = temp->left;
                else prev->left = temp->right; 
            }
            else{
                if(temp->left) prev->right = temp->left;
                else prev->right = temp->right;
            }
        }
        
    }

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
    // cout<<"Inorder Predecessor : "<<InorderPredecessor(root,10);
    // cout<<endl;
    // cout<<"Inorder Successor : "<<InorderSuccessor(root,10);
    deleteBST(root,9);
    inorder(root);
    

    return 0;
}