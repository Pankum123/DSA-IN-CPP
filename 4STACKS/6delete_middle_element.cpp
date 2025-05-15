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

void deletemiddle(stack<int>&s,int count,int size){
    
    //base case
    if(count == size/2){
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    deletemiddle(s,count+1,size);

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
    
    int n = s.size();
    int count = 0;
    deletemiddle(s,count,n);

    cout<<"\n";

    printstack(s);
    
return 0;
}