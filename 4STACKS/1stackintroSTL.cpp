#include<iostream>
#include<stack>
using namespace std;

void PrintStack(stack<int> s)
{
	// If stack is empty
	if (s.empty())
		return;

	int x = s.top();
	s.pop();
	cout << x << ' ';
	PrintStack(s); //recursion
	s.push(x);	  // Push the element back
}

int main(){

    //creation of stack
    stack<int> s;

    //push operation 
    s.push(10);
    s.push(32);
    s.push(39);
    s.push(74);

    //print stack
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    PrintStack(s);
    cout<<"\n";
    cout<<"size of stack is "<<s.size()<<endl;
    cout<<"printing top element "<< s.top() <<endl;

    //pop
    s.pop();
    PrintStack(s);
    cout<<"\n";
    cout<<"size of stack is "<<s.size()<<endl;
    cout<<"printing top element "<< s.top() <<endl;

    s.pop();
    PrintStack(s);
    cout<<"\n";
    cout<<"size of stack is "<<s.size()<<endl;
    cout<<"printing top element "<< s.top() <<endl;

    s.pop();
    s.pop();

    if(s.empty()){
        cout<<"stack is empty "<< endl;
    }
    else{
        cout<<"stack is not empty "<< endl;
    }

    
return 0;
}