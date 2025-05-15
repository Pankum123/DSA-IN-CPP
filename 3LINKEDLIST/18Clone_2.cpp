// CLONE A LINKED LIST WITH NEXT AND RANDOM POINTER
// WITHOUT USING MAP

#include<iostream>
#include<bits/stdtr1c++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *random;

    node(int data){
       this -> data = data;
       this -> next = NULL;
       this -> random = NULL;
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
        //step1 : create a clone
        node* clonehead = NULL;
        node* clonetail = NULL;

        node* temp = head;

        while(temp != NULL){
            insertattail(clonehead,clonetail,temp->data);
            temp = temp->next;
        } 

        //step2 : clonenodes add in between original list
        node* originalnode = head;
        node* clonenode = clonehead;
        while(originalnode != NULL && clonenode != NULL){
        node* next = originalnode->next;
        originalnode->next = clonenode;
        originalnode = next;

        next = clonenode->next;
        clonenode->next = originalnode;
        clonenode = next;
       }

        //step3 : random pointer copy
        temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                temp->next->random = temp->random ? temp->random->next : temp->random;
            }
            temp = temp->next->next;

        }

        //steo4 : revert chjanges done in step 2
        originalnode = head;
        clonenode = clonehead;
        while(originalnode != NULL && clonenode != NULL){
            originalnode->next = clonenode->next;
            originalnode = originalnode->next;

            if(originalnode != NULL){
                clonenode -> next = originalnode -> next;
            }
            clonenode = clonenode -> next;
       }

        //step5 : return ans;
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