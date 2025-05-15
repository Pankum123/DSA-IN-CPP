#include<iostream>
#include<stack>
using namespace std;

void printstack(stack<int> s)
{
	// If stack is empty
	if (s.empty())
		return;

	int x = s.top();
	s.pop();
	cout << x << ' ';
	printstack(s); //recursion
	s.push(x);	  // Push the element back
}   

void insertatbottom(stack<int>&s,int value){
    
    //base case
    if( s.empty() ){
        s.push(value);
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    insertatbottom(s,value);

    s.push(num);   
}


int main(){

    stack<int> s;

    s.push(1);
    s.push(5);
    s.push(12);
    s.push(8);
   // s.push(4);

    printstack(s);
    
    insertatbottom(s,10);

    cout<<"\n";

    printstack(s);
    
return 0;
}