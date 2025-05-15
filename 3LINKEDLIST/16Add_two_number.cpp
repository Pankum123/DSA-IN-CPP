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
void insertattail(node* &head,node* &tail,int value){

      // new node create
      node* temp = new node(value);
      if(head==NULL){
        head = temp;
        tail = temp;
        return;
      }
      else{
      tail->next=temp;
      tail=temp;
      }
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

// find sum
node* add(node* first,node* second){

    int carry = 0;
    node* anshead = NULL;
    node* anstail = NULL;

    while(first != NULL || second != NULL || carry != 0){

        int val1 = 0;
        if(first != NULL)
            val1 = first->data;

        int val2 = 0;
        if(second != NULL)
            val2 = second->data;

        int sum = carry + val1 + val2;
        int digit = sum % 10;
        //create node and in answer linked list
        insertattail(anshead,anstail,digit);
        carry = sum/10;

        if(first!=NULL)
            first = first->next;
        if(second!=NULL)
            second = second->next;
    }

    return anshead;
}
    node* addtwolist(node* first,node* second){

        //step1 -> reverse input LL
        first = reverse(first);
        second = reverse(second);

        //step2 -> add 2 LL
        node* ans = add(first,second);

        //step3 -> 
        ans = reverse(ans);   

        return ans; 
    }
  
   
int main()
{
    
    node* first =NULL;
    node* tail1 = NULL;
    node* second=NULL;
    node* tail2 = NULL;
  
    // InsertAtHead
    insertattail(first,tail1,8);
    insertattail(first,tail1,5);
    insertattail(first,tail1,8);
    insertattail(first,tail1,8);
    insertattail(first,tail1,8);
    
    print(first);

   // insertattail(second,9);
    insertattail(second,tail2,8);
    insertattail(second,tail2,9);
    insertattail(second,tail2,9);
    insertattail(second,tail2,9);
    print(second);

    node* ans = addtwolist(first,second);
    print(ans);

    return 0;
}
