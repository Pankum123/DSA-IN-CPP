#include<iostream>
using namespace std;

int binarysearch(int a[],int n,int key){
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(key==a[mid])
        return mid;
        else{
            if(key<a[mid])
            end=mid-1;
            else
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }    
        return -1;
}
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<"enter a number to search"<<endl;
    int key;
    cin>>key;
    int found=binarysearch(a,10,key);
    if(found==-1)
    cout<<"key  is absent"<<endl;
    else
    cout<<"key is present at position "<<found<<endl;
    return 0;
}
