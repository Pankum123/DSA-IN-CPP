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
	// cout << x << ' ';
	printstack(s); //recursion
    cout << x << ' ';
	s.push(x);	  // Push the element back
}   

void sortedinsert(stack<int>&s,int num){
    
    //base case
    if( s.empty() || ( !s.empty() && s.top() < num) ){
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    //recursive call
    sortedinsert(s,num);

    s.push(n);   
}

void sortstack(stack<int>&s){
    
    //base case
    if( s.empty() ){
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    sortstack(s);

    sortedinsert(s,num);   
}


int main(){

    stack<int> s;

    s.push(-1);
    s.push(5);
    s.push(-12);
    s.push(18);
    s.push(4);

    printstack(s);
    
    sortstack(s);

    cout<<"\n";

    printstack(s);
    
return 0;
}