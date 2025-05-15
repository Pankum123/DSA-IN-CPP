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


// delete a node 
void deletenode(node* &prev,node* &curr,node* &tail){

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
         
         
    // handling tail value
    
        if (prev->next == NULL) {
            tail = prev;
            cout<<"hi pankaj last node ko delet kiye ho"<<endl;
        }          
    
}



    void removeduplicate(node* &head,node* &tail){
        //empty linked list
        if(head==NULL){
            return; 
        }
        node* curr=head;
       

        while(curr!=NULL){

            if(curr->next!=NULL&&curr->data==curr->next->data){
                node* next_next=curr->next->next;
                node* nodeToDelete=curr->next;
                deletenode(curr,nodeToDelete,tail);
               // delete(nodeToDelete);             
               // curr->next=next_next;
            }
          else {
            curr=curr->next;
          }
        }
    }

   
   
int main()
{
    node *node1=new node(1);
    print(node1);
   
    node* head =node1;
    node* tail=node1;
  
    insertattail(tail,1);
    print(head);
    insertattail(tail,2);
    print(head);
    insertattail(tail,2);
    print(head);
    insertattail(tail,3);
    print(head);
    insertattail(tail,3);
    print(head);
    insertattail(tail,3);
    print(head);
    insertattail(tail,3);
    print(head);
    insertattail(tail,4);
    print(head);
    insertattail(tail,4);
    print(head);
    insertattail(tail,4);
    print(head);

    //remove duplicate
    cout<<"remove duplicate"<<endl;
    removeduplicate(head,tail);
    print(head);
   
   
}
