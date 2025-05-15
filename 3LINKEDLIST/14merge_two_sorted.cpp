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

void solve(node* &first,node* &second){

        // if only one element is present in first element
        if(first->next ==NULL){
            first ->next = second;
            return;
        }
        
        node* curr1 = first;
        node* next1 = first->next;
        node* curr2 = second;
        node* next2 = second->next;

        while(next1!=NULL&&curr2!=NULL){
            
            if(curr1->data <= curr2->data && curr2->data <=next1->data){

                //add node in between the first list
                curr1->next = curr2;
                next2 = curr2 ->next;
                curr2->next = next1;
                //update pointer
                curr1 = curr2;
                curr2 = next2;
            }
            else{
                // curr1 and next1 ko aage badhana padega
                curr1 = next1;
                next1 = next1->next;

                if(next1==NULL){
                    curr1 ->next = curr2;
                    return;
                }
            }
            
        }
       

}

void mergetwosort(node* &first,node* &second){

        if(first==NULL){
            first = second;
            return;
        }
        if(second==NULL){
            return;
        }

        if(first->data <= second->data){
            solve(first,second);
        }
        else{
            solve(second,first);
        }
}
int main()
{
   
    node* first =NULL;
    node* tail1=NULL;

    node* second =NULL;
    node* tail2=NULL;
  
    // insertathead(first,17);
    // insertathead(first,7);
    insertathead(first,4);
   // insertathead(first,1);
    insertathead(second,30);
    insertathead(second,25);
    insertathead(second,20);
    // insertathead(second,11);
    // insertathead(second,3);
    // insertathead(second,2);

    cout<<"first list is : ";
    print(first);

    cout<<"second list is : ";
    print(second);

    cout<<"merge two sorted list is :";
    mergetwosort(first,second);
    print(first);

   
   
   
   
}
