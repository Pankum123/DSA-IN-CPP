#include<iostream>
using namespace std;

int linearsearch(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key)
        return i;
    }
    return -1;
}
int main()
{
    int a[10]={2,43,34,6,54,8,7,45};
    cout<<"enter a number to search"<<endl;
    int key;
    cin>>key;
    int found=linearsearch(a,10,key);
    if(found==-1)
    cout<<"key  is absent"<<endl;
    else
    cout<<"key is present at position "<<found<<endl;
    return 0;
}