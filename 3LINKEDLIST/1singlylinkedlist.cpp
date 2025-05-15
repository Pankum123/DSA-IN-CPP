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

// delete a node 
void deletenode(node* &head,node* &tail,int position){
     
     //deleting first or start node
    if(position==1){
        node* temp=head;
        head=head->next;

        // memory free
        temp->next=NULL;
        delete temp;
    }
    else{

        // deleting any middle node or last node
        node* curr=head;
        node* prev=NULL;

        
        int cnt=1;
        while(cnt < position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
         
         
    // handling tail value
    
        if (prev->next == NULL) {
            tail = prev;
            cout<<"hi pankaj last node ko delet kiye ho"<<endl;
        }     

     
    }
}

int main()
{
    // create new node
    node *node1=new node(1);
    print(node1);
   // cout<<node1->data<<endl<<node1->next<<endl;
     
   // head pointed to node1
    node* head =node1;
    node* tail=node1;
   // print(head);

    // InsertAtHead

    insertathead(head,12);
    print(head);
    insertathead(head,20);
    print(head);


/* for(int i=1;i<5;i++){
        insertathead(head,2*i);
        print(head);
    }
*/

    


//  insert at tail

    insertattail(tail,45);
    print(head);

    insertattail(tail,50);
    print(head);

/*    for(int i=1;i<5;i++){
        insertattail(tail,3*i);
        print(head);
    }
*/

// insert at positrion
    insertatposition(head,tail,3,100);
    print(head);

   insertatposition(head,tail,1,200);
    print(head);

    insertatposition(head,tail,5,300);
    print(head);

    // verify head and tail
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    // delete a node

    deletenode(head,tail,1);
    print(head);

    deletenode(head,tail,7);
    print(head);

    deletenode(head,tail,2);
    print(head);

    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    return 0;
}
