#include<iostream>
using namespace std;

class node{

    public :
    int data;
    node* next;

    // constructure 
    node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~node(){
        int value=this->data;

        // memory free
        
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        
        cout<<"memory is free for the node with data :"<<value<<endl;
    }
};

// print the linklist
void print(node* &head){
    if(head==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//inserting new node at head or starting

void insertathead(node* &head,int d){

        // new node create
        node* temp=new node(d);
        temp->next=head;
        head=temp;
}

//inserting new node at tail or end

void insertattail(node* &tail,int d){

      // new node create
      node* temp=new node(d);
      tail->next=temp;
      tail=temp;
}

node* findmid(node* head){
    node* slow = head;
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left,node* right){
    if(left == NULL)
        return right;

    if(right == NULL)
        return left;

    node* ans = new node(-1);
    node* temp = ans;

    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans -> next;
    return ans;
}

node* mergesort(node* head){

    //base case
    if(head == NULL || head->next == NULL){
        return head; 
    }

    //break linked into 2 halvs , after finding mid
    node* mid = findmid(head);

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    //recursive calls to sort both halvs
    left = mergesort(left);
    right = mergesort(right);

    //merge both left and right halves
    node* result = merge(left,right);

    return result;
}
  

int main()
{
    
    node *node1=new node(1);
    node* head =node1;
    node* tail=node1;
   
    insertathead(head,312);
    insertathead(head,20);
    insertathead(head,10);
    insertathead(head,20);
    insertathead(head,120);
    insertathead(head,50);
    print(head);

    node* ans = mergesort(head);
    print(ans);


    return 0;
}
