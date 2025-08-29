#include<iostream>
#include<queue>
#include<climits>   
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

Node *BuildTree(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

// Preorder Traversal of a Binary Tree
void preorder(Node* root){
    if(root==NULL) return;
    cout<< root->data << " ";
    preorder(root->left);   
    preorder(root->right);
}

// Inorder Traversal of a Binary Tree
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}

// Postorder Traversal of a Binary Tree
void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<< root->data << " ";
}

// level order Traversal
void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<temp->data<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        
    }
}

// Count Total Nodes in Binary Tree 
int TotalNode(Node* root){
    if(root==NULL) return 0;


    // int leftNode = TotalNode(root->left);
    // int rightNode = TotalNode(root->right);
    // int totalNode = 1 + leftNode + rightNode;
    // return totalNode;

    return 1 + TotalNode(root->left) + TotalNode(root->right);
}

// Count Leaf Nodes (Nodes with 0 children) 
int CountLeaf(Node* root){
    if(root==NULL) return 0;
    if(!root->left && !root->right) return 1;

    // int leftLeaf = CountLeaf(root->left);
    // int rightLeaf = CountLeaf(root->right);
    // int totalLeaf = leftLeaf + rightLeaf;
    // return totalLeaf;

    return CountLeaf(root->left) + CountLeaf(root->right);
}

// Count internal nodes (nodes with at least 1 child) 
int CountInternalNode(Node* root){
    if(root==NULL) return 0;
    if(!root->left && !root->right) return 0;

    // int leftInternalNode = CountInternalNode(root->left);
    // int rightInternalNode = CountInternalNode(root->right);
    // int totalInternal = 1 + leftInternalNode + rightInternalNode;
    // return totalInternal;

    return 1 + CountInternalNode(root->left) + CountInternalNode(root->right);
}

// Count full nodes (nodes with 2 children) 
int CountFullNode(Node* root){
    if(root==NULL) return 0;
    if(!root->left || !root->right) return 0;

    // int leftFullNode = CountFullNode(root->left);
    // int rightFullNode = CountFullNode(root->right);
    // int totalFull = 1 + leftFullNode + rightFullNode;
    // return totalFull;

    return 1 + CountFullNode(root->left) + CountFullNode(root->right);
}

// Maximum depth (height) of tree 
int MaximumDepth(Node* root){
    if(root==NULL) return 0;
    return 1 + max(MaximumDepth(root->left),MaximumDepth(root->right));
}

// Manimum depth (height) of tree 
int MinimumDepth(Node* root){
    if (!root) return 0; 
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + MinimumDepth(root->right);
    if (!root->right) return 1 + MinimumDepth(root->left);
    return 1 + min(MinimumDepth(root->left), MinimumDepth(root->right));
}

// Sum of all Nodes
int SumOfNode(Node* root){
    if(root==NULL) return 0;

    // int leftSum = SumOfNode(root->left);
    // int rightSum = SumOfNode(root->right);
    // int totalSum = root->data + leftSum + rightSum;
    // return totalSum;

    return root->data + SumOfNode(root->left) + SumOfNode(root->right);
}

// Sum of Leaf Node
int SumOfLeafNode(Node* root){
    if(root==NULL) return 0;
    if(!root->left && !root->right) return root->data;
    return SumOfLeafNode(root->left) + SumOfLeafNode(root->right);
}

// Product of all Nodes
int ProductOfNode(Node* root){
    if(root==NULL) return 1;

    // int leftProduct = ProductOfNode(root->left);
    // int rightProduct = ProductOfNode(root->right);
    // int totalProduct = root->data * leftProduct * rightProduct;
    // return totalProduct;

    return root->data * ProductOfNode(root->left) * ProductOfNode(root->right);
}

//  Maximum value
int maximumvalue(Node* root,int maxval){
    if(root==NULL) return INT_MIN;
    return max(root->data,max(maximumvalue(root->left,maxval),maximumvalue(root->right,maxval)));
}

//Manimum Value
int manimumvalue(Node* root,int maxval){
    if(root==NULL) return INT_MAX;
    return min(root->data,min(manimumvalue(root->left,maxval),manimumvalue(root->right,maxval)));
}

// isExist
bool isExists(Node* root, Node* x){
    if(root==NULL) return false;
    if(root->data==x->data) return true;
    return isExists(root->left,x) || isExists(root->right,x);
}

// lowestCommonAncestor
Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if(root==NULL) return NULL;
    Node* ans = lowestCommonAncestor(root->left,p,q);
    if(ans != NULL) return ans;
    ans = lowestCommonAncestor(root->right,p,q);
    if(ans != NULL) return ans;
    if(isExists(root,p) && isExists(root,q)) return root;
    else return NULL;
}

// level of Tree
int level(Node* root){
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
// no of Height = level - 1
// no of edge = level - 1

// print elements of nth level
void nthLevel(Node* root,int current,int xlevel){
    if(root==NULL) return;
    if(current==xlevel) cout<<root->data<<" ";
    nthLevel(root->left,current+1,xlevel);
    nthLevel(root->right,current+1,xlevel);
}






int main() {

    Node* root = BuildTree();
    preorder(root);
    cout << endl;
    // inorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // LevelOrderTraversal(root);
    // cout<< endl;
    // cout<<"Total no of Node = "<<TotalNode(root);
    // cout<< endl;
    // cout<<"Total no of Leaf Node = "<<CountLeaf(root);
    // cout<< endl;
    // cout<<"Total no of internal Node = "<<CountInternalNode(root);
    // cout<< endl;
    // cout<<"Total no of Full Node = "<<CountFullNode(root);
    // cout<< endl;
    // cout<<"Maximum Depth of Tree = "<<MaximumDepth(root);
    // cout<< endl;
    // cout<<"Minimum Depth of Tree = "<<MinimumDepth(root);
    // cout<< endl;
    // cout<<"Total sum of Node = "<<SumOfNode(root);
    // cout<< endl;
    // cout<<"Total sum of Leaf Node = "<<SumOfLeafNode(root);
    // cout<< endl;
    // cout<<"Total Product of Node = "<<ProductOfNode(root);
    // cout<< endl;
    // cout<<"Maximum Node = "<<maximumvalue(root,INT_MIN);
    // cout<< endl;
    // cout<<"Manimum Node = "<<manimumvalue(root,INT_MAX);
    // cout<< endl;
    // cout<<"lowestCommonAncestor = "<<lowestCommonAncestor(root,root->right->left,root->right->right)->data;
    // cout<< endl;
    // cout<<"no of level = "<<level(root);
    // cout<< endl;
    nthLevel(root,1,3); 
    cout<< endl;

    
    return 0;
}