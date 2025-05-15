
#include<iostream>
#include<map>
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


// dedect node in CLL
  bool dedectloop(node* head){
        if(head==NULL){
            return false;
        }

        map<node*, bool> visited;

        node* temp=head;
        while(temp!=NULL){

            //cycle is present
            if(visited[temp]==true){
                cout<<"present on element "<< temp->data <<endl;
                return true;
            }
            visited[temp]=true;
            temp=temp->next;
        }
        return false;
    }

//floyddedectloop
    node* floydDetectLoop(node* head) {

    if(head == NULL)
        return NULL;

    node* slow = head;
    node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout<<"present at "<< slow->data<<endl;
            return slow;
        }
    }

    return NULL;
  }

//starting node
    node* getStartingnode(node* head) {

    if(head == NULL) 
        return NULL;

    node* intersection = floydDetectLoop(head);

    if(intersection == NULL)
        return NULL;

    node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}

//remove loop
    void removeLoop(node *head)
{
    if( head == NULL)
        return;

    node* startOfLoop = getStartingnode(head);

     if(startOfLoop == NULL)
        return; //return head; 
      
    node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 
    temp -> next = NULL;
}

int main()
{
    
    node *node1=new node(10);
  
    node* head =node1;
    node* tail=node1;
  
    insertattail(tail,12);
    insertattail(tail,15);
    insertatposition(head,tail,4,22);
    print(head);

    tail->next=head->next;

    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

   // print(head);//infinite loop 

//    if(dedectloop(head)){
//     cout<<"cycle is present "<<endl;
//    }
//    else{
//     cout<<"no cycle"<<endl;
//    }

   if(floydDetectLoop(head)!=NULL){
    cout<<"cycle is present "<<endl;
   }
   else{
    cout<<"no cycle"<<endl;
   }

   node* loop = getStartingnode(head);
   cout<<"loop starts at "<< loop->data<<endl;

   removeLoop(head);
   print(head);
    return 0;
}
