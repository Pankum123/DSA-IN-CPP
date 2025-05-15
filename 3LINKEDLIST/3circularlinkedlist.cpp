#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;

    //constructure

    node(int data){
        this->data=data;
        this->next=NULL;
    }

    //destructor
    ~node(){
        int value;
        value=this->data;

        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for the node with data :"<<value<<endl;
    }

};    

    //print node
    void print(node* &tail){
        node* temp=tail;

        //empty list
    
        if(tail==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
    
        do
        {
            cout<<tail->data<<" ";
            tail=tail->next;
        } while (tail!=temp);

        cout<<endl;
    }

    //insert at node
    void insertnode(node* &tail,int element,int d){

        //empty linked list
        if(tail==NULL){
            node* newnode=new node(d);
            tail=newnode;
            newnode->next=newnode;
        }
        else{
            //non empty node
            // assuming that element is present in the list

            node* curr = tail;
            while (curr->data!=element)
            {
                curr=curr->next;
            }

            // element found and it means current node representing found element
            node* temp=new node(d);
            temp->next=curr->next;
            curr->next=temp;
            
        }

    }



    //delete a node
    void deletenode(node* &tail,int value){
        //empty linked list
        if(tail==NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        //non empty list
        else{
            // assuming that the given value present in the linked list
            
            node* prev=tail;
            node* curr=prev->next;

            while(curr->data!=value){
                prev=curr;
                curr=curr->next;
            }

            prev->next=curr->next;

            // 1 node linked list
            if(curr==prev){
                tail=NULL;
            }

            //>=2 node linked list
           else if(tail==curr) {
                tail=prev;
            }
            curr->next=NULL;
            delete curr;
        }
    }
int main(){

    node* tail=NULL;

    // inserting in empty list
    insertnode(tail,4,7);
    print(tail);


    insertnode(tail,7,9);
    print(tail);
/*
    insertnode(tail,9,71);
    print(tail);

    insertnode(tail,7,100);
    print(tail);

    insertnode(tail,9,500);
    print(tail);

    insertnode(tail,7,1000);
    print(tail);

    insertnode(tail,71,2000);
    print(tail);


    deletenode(tail,500);
    print(tail);

    deletenode(tail,100);
    print(tail);

    deletenode(tail,7);
    print(tail);
*/
     
    deletenode(tail,7);
    print(tail);



    return 0;
}