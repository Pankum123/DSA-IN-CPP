// everyone knows celebrity
// celebrity knows no ones

/* approach : 
 celebrity ka row -> all 0
 celebrity ka column -> all 1 except diagonal element */ 

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool knows(vector< vector<int> >&M,int a,int b,int n){
    if(M[a][b] == 1)
        return true;
    else
        return false;
}

int celebrity(vector< vector<int> >&M,int n){
    stack<int> s;
    //step1: push all element
    for(int i=0;i<n;i++){
        s.push(i);
    }

    //step2:get two elements and compare them

    while(s.size() > 1){

        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(M,a,b,n)){
            s.push(b);
        }
        else{
            s.push(a);
        }

    }
    int ans = s.top();
    //step3: single element in stack is potential celeb
    //so verify it

   
    int zerocount = 0;
    for(int i=0;i<n;i++){
        if(M[ans][i] == 0)
            zerocount++;
    }
    //all zeroes
    if(zerocount != n)
       return -1;

    //column check
    int onecount = 0;
    for(int i=0;i<n;i++){
        if(M[i][ans] == 1)
            onecount++;
    }
    if(onecount != n-1)
        return -1;

    return ans;
}
int main(){
    vector< vector<int> > M = {{0,1,0},{0,0,0},{0,1,0}};
    int n = M.size(); // no of row 3

    int ans = celebrity(M,n);

    cout<<"celebrity is "<<ans<<endl;
   
return 0;
}