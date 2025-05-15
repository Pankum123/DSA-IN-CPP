#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

vector<int> nextsmallerelement(int* arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i>=0; i--){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        //ans is stack ka top
        ans[i]= s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevsmallerelement(int* arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = 0; i<n; i++){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        //ans is stack ka top
        ans[i]= s.top();
        s.push(i);
    }
   
    return ans;
}

int largest_rectangle_area(int* heights, int n){
    
    vector<int> next(n);
    next = nextsmallerelement(heights,n);

    vector<int> prev(n);
    prev = prevsmallerelement(heights,n);

    int area = INT_MIN;
    for(int i=0; i<n; i++){
        int l = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newarea = l*b;
        
        area = max(area,newarea);
    }
   
    return area;
}

int maxarea(int M[][4],int n,int m){
    
    //compute area for first row
    int area = largest_rectangle_area(M[0],m);

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            //row update : by adding previous row value
            if(M[i][j] != 0)
            M[i][j] = M[i][j] + M[i-1][j];
            else
            M[i][j] = 0;
        }
        //entire row is updated now
        int newarea = largest_rectangle_area(M[i],m);
        area = max(area,newarea);
    }
    return area;
}
int main(){
    
    int M[4][4] = {{0,1,1,0},
                   {1,1,1,1},
                   {1,1,1,1},
                   {1,1,0,0}};
    int n=3;
    int m=4;
    int area = maxarea(M,n,m);
    cout<<"max area = "<<area<<endl;
return 0;
}