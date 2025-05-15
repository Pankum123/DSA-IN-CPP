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

//2nd method without 
void sorted1(node* &head){
    node* zerohead = new node(-1);
    node* zerotail = zerohead;
    node* onehead = new node(-1);
    node* onetail = onehead;
    node* twohead = new node(-1);
    node* twotail = twohead;

    node* curr = head;
    //create saparate list 0s, 1s, and 2s
    while (curr != NULL){
        int value = curr->data;

        if(value==0){
            insertattail(zerotail,curr);
        }
        else if(value==1){
            insertattail(onetail,curr);
        }
        else if(value==2){
            insertattail(twotail,curr);
        }

        curr = curr->next;
    }
        //merge 3 sublist

        // is list not empty
        if(onehead->next != NULL){
            zerotail->next = onehead->next;
        }
        else{
            // 1s list ->empty
              zerotail->next = twohead->next;
        }

        onetail->next = twohead->next;
        twotail->next = NULL;

        // setup head
        head = zerohead->next;

        //delete dummy nodes
        zerohead->next = NULL;
        delete zerohead;
        onehead->next = NULL;
        delete onehead;
        twohead->next = NULL;
        delete twohead;  
}

// 1st method 
void sorted(node* &head){
    node* temp = head;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    while(temp!=NULL){
        if(temp->data==0) count0++;
        if(temp->data==1) count1++;
        if(temp->data==2) count2++;
        temp = temp->next;
    }

    temp = head;
   
    while(temp!=NULL){
        if(count0!=0){
            temp->data = 0;
            count0--;
        }
        else if(count1!=0){
            temp->data = 1;
            count1--;
        }
        else if(count2!=0){
            temp->data = 2;
            count2--;
        }
         temp = temp->next;
 
    }
}

 
   
   
int main()
{
    node *node1=new node(1);
    print(node1);
   
    node* head =node1;
    node* tail=node1;
  
    insertathead(head,2);
    insertathead(head,0);
    insertathead(head,1);
    insertathead(head,0);
    insertathead(head,2);
    insertathead(head,1);
    insertathead(head,0);
    print(head);

    // sorted(head);
    // print(head);

    sorted1(head);
    print(head);
   
   
   
}
