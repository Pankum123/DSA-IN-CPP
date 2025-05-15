#include<iostream>
using namespace std;


class node{
    public:
    int data;
    node* prev;
    node* next;

    //constructure
    node(int d){
        this->data=d;
        this->prev=NULL;
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

//traversing a linked list
    void print(node* head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}

//length of linledlist
int getlength(node* head){
    node* temp = head;
    int cnt=0;

    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }

    return cnt;
}

//insert at head 
void insertathead(node* &head,node* &tail,int d){

    //empty list
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
        tail=head;
    }

    else{
        node* temp=new node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
        }
}

//insert at tail 
void insertattail(node* &head,node* &tail,int d){

    if(tail==NULL){

        node* temp=new node(d);
        tail=temp;
        head=temp;
    }

    else{       
    node* temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}
 
// insertat at position
void insertatposition(node* &head,node* &tail,int position,int d){
    
        // insert at starts
    if(position==1){
        insertathead(head,tail,d);
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
        insertattail(head,tail,d);
        return;
    }

    //creating a node for d
    node* nodetoinsert=new node(d);

    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;

}
    
// delete a node
void deletenode(node* &head,node* &tail,int position){

        //deleting first or start node
    if(position==1){
        node* temp=head;
        
        temp->next->prev=NULL;
        head=temp->next;
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

        curr->prev=NULL;
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

//reverse linked list DLL
node* reverse(node* &haed){
    
}

int main()
{

/*
    //new node create
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
*/
    node* head=NULL;
    node* tail=NULL;

    //length of linledlist
    //cout<<"length="<<getlength(head) <<endl;

    insertathead(head,tail,11);
    print(head);

    insertathead(head,tail,13);
    print(head);

    insertathead(head,tail,15);
    print(head);

    
    // insertat tail linked list
    
    insertattail(head,tail,20);
    print(head);

    insertattail(head,tail,40);
    print(head);

    //insertat at posirion
    insertatposition(head,tail,3,100);
    print(head);

    insertatposition(head,tail,1,200);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    insertatposition(head,tail,8,1000);
    print(head);


    // delete node

    deletenode(head,tail,1);
    print(head);

    deletenode(head,tail,7);
    print(head);

    deletenode(head,tail,4);
    print(head);
    
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    
    




    return 0;  
}