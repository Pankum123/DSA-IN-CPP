#include<iostream>
#include<stack>

using namespace std;

bool isvalidparanthesis(string str){

     stack<char> s;
     for(int i=0;i<str.length();i++){
        char ch = str[i];

        //if opening bracket, stack push
        //if close bracket, stack pop
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else{

            //for closing bracket
            if(!s.empty()){
                char top = s.top();
                if( (ch == ')' && top == '(' ) ||
                    (ch == '}' && top == '{' ) ||
                    (ch == ']' && top == '[' ) ) {

                       s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}
int main(){

    
    string str = "()[[{()}{}]()]";
    if( isvalidparanthesis(str) ){
        cout<<"balanced";
    }
    else{
        cout<<"not balanced";
    }

return 0;
}