// CLONE A LINKED LIST WITH NEXT AND RANDOM POINTER

#include<iostream>
#include<bits/stdtr1c++.h>
using namespace std;

// link list node
class node{
    public:
    int data;
    node *next;
    node *random;

    node(int x){
        data = x;
        next = NULL;
        random = NULL;
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

    void insertattail(node* &head,node* &tail,int value){
      // new node create
      node* newnode = new node(value);
      if(head==NULL){
        head = newnode;
        tail = newnode;
        return;
      }
      else{
      tail->next=newnode;
      tail=newnode;
      }
    }

    
    node *Clone(node *head){
        //step1 : create a clone list
        node* clonehead = NULL;
        node* clonetail = NULL;

        node* temp = head;

        while(temp != NULL){
            insertattail(clonehead,clonetail,temp->data);
            temp = temp->next;
        } 

        //step2 : create a map
       unordered_map<node*, node*> oldtonewnode;

       node* originalnode = head;
       node* clonenode = clonehead;
       while(originalnode != NULL && clonenode != NULL){
        oldtonewnode[originalnode] = clonenode;
        originalnode = originalnode->next;
        clonenode = clonenode->next;
       }

       originalnode = head;
       clonenode = clonehead;

       while(originalnode != NULL){
        clonenode->random = oldtonewnode[originalnode->random];
        originalnode = originalnode->next;
        clonenode = clonenode->next;
       }
       return clonehead;
    }




int main(){

    node* head = NULL;
    node* tail = NULL;

    insertattail(head,tail,1);
    insertattail(head,tail,2);
    insertattail(head,tail,3);
    insertattail(head,tail,4);
    print(head);

    head->next->random = head->next->next->next;
    head->next->next->random = head;
    print(head);

    node* clonehead = Clone(head);
    print(clonehead);  



return 0;
}