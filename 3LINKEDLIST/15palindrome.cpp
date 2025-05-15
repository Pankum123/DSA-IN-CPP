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
void insertattail(node* &tail,node* &curr){
    tail->next = curr;
    tail = curr;
}

//find middle node
 node* getmid(node* head){
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
 } 

 //find reverse 
 node* reverse(node* head){
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
 } 

//palindrome
 bool ispalindrome(node* head){
    if(head->next == NULL){
        return true;
    }

    //step1 -> find middle
    node* middle = getmid(head);
    cout<<"middle "<<middle->data <<endl;

    //step2 -> reverse list after middle
    node* temp = middle->next;
    middle->next = reverse(temp);

    //step3 -> compare both halves
    node* head1 = head;
    node* head2 = middle->next;

    while(head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    //step4 ->repeat step2 (optional)
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
 } 

int main()
{
    //node *node1=new node(1);
    node* head =NULL;
    node* tail=NULL;
  
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,5);
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    print(head);

    int value = ispalindrome(head);
    if(value){
        cout<<"palindrome hai "<<endl;
    }
    else{
        cout<<"palindrome nahi hai "<<endl;
    }

    
   
   
   
}
