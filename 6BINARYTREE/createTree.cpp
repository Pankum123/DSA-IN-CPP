#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main() {
    // stack allocation
    cout<<"stack allocation\n";
    Node root1(1);
    Node leftchild(2);
    Node rightchild(3);

    root1.left = &leftchild;
    root1.right = &rightchild;

    cout<< "Root Node: " << root1.data << endl;
    cout<< "Left Child: " << root1.left->data << endl;
    cout<< "Right Child: " << root1.right->data << endl;

    // heap allocation
    cout<<"heap allocation\n";
    Node* root2 = new Node(5);
    // Node* leftchild2 = new Node(6);
    // Node* rightchild2 = new Node(7);

    // root2->left = leftchild2;
    // root2->right = rightchild2;
    root2->left = new Node(6);
    root2->right = new Node(7);

    cout<<"Root Node: " << root2->data << endl;
    cout<<"Left Child: " << root2->left->data << endl;
    cout<<"Right Child: " << root2->right->data << endl;

    return 0;
}