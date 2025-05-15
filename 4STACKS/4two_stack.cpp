#include<iostream>
using namespace std;

class twostack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;



    //initialize twostack
    twostack(int s){
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    //push in stack1
    void push1(int num){
        //atleast a empty space present
        if(top2 - top1 >1){
            top1++;
            arr[top1] = num;
        }
        else{
            cout<<"stack overflow" <<endl;
        }

    }

    //push in stack2
    void push2(int num){
        if(top2 - top1 >1){
            top2--;
            arr[top2] = num;
        }
        else{
            cout<<"stack overflow" <<endl;
        }

    }

    //pop from stack 1 and return popped element
    int pop1(){
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    //pop from stack 2 and return popped element
    int pop2(){
         if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};

int main(){

    twostack sta(5);
    sta.push1(1);
    sta.push1(2);
    sta.push2(3);
    sta.push2(1);
    sta.push2(2);
    sta.push1(3); //stack overflow
    sta.pop1();
    sta.pop2();
    sta.push1(6);
    sta.push2(6);
    sta.push1(6); //stack overflow
return 0;
}