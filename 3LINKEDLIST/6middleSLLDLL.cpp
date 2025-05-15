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
        temp=temp->next;
        cnt++;
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

// middle of SLL
int middle(node* &head)
{
    //2nd method
    if(head==NULL||head->next==NULL){
        return head->data;
    }
    else if(head->next->next==NULL){
        return head->next->data;
    }
    
        node* slow=head;
        node* fast=head->next;
            while(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
                if(fast!=NULL){
                    fast=fast->next;
                }
            }
        return slow->data;
    

    //1st method
 /*
    node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    cout<<"no of element = "<<cnt<<endl;
    temp=head;
    int n=cnt/2;
    while(n--){
        temp=temp->next;
    }
    return temp->data;
 */
}

int main()
{
    // create new node
    node *node1=new node(1);
    print(node1);
   
    node* head =node1;
    node* tail=node1;

    // InsertAtHead
    insertathead(head,12);
    print(head);
    insertathead(head,20);
    print(head);

    // insert at tail
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

    // middle of SLL
    cout<<"middle of node is = "<<middle(head)<<endl;
  
    return 0;
}
