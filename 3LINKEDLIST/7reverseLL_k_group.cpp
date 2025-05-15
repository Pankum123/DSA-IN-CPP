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

// insert new node at given position
void insertatposition(node* &head,node* &tail,int position,int d){

    // insert at starts
    if(position==1){
        insertathead(head,d);
        return;
    }

      node* temp=head;

      int cnt=1;
      while(cnt<position-1){
        cnt++;
        temp=temp->next;
      }

    // insert at last position
    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }

    //creating a node for d
    node* nodetoinsert=new node(d);

    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
      
}

    node* reverse(node* &head,int k){

        //base case 
        if(head==NULL){
            return head;
        }

        //step1:reverse first k node
        node* prev=NULL;
        node* curr=head;
        node* next=NULL;
        int count=0;
        while(curr!=NULL && count < k){

            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        //step2: recursion dekhlega aage ka 
        if(next!=NULL){
            head->next=reverse(next,k);
        }
        //step3:return head of reversed list
        return prev;
    }

 
   
  
   
int main()
{
    node *node1=new node(1);
    print(node1);
   
    node* head =node1;
    node* tail=node1;
  
    // InsertAtHead
    insertathead(head,12);
    print(head);
    insertathead(head,20);
    print(head);

//  insert at tail

    insertattail(tail,45);
    print(head);

    insertattail(tail,50);
    print(head);

    // insert at positrion
    insertatposition(head,tail,3,100);
    print(head);

    insertatposition(head,tail,1,200);
    print(head);

    insertatposition(head,tail,5,300);
    print(head);
    // insertatposition(head,tail,5,500);
    // print(head);

    cout<<"reverse list"<<endl;
    head= reverse(head,3);
    print(head);
   
}
