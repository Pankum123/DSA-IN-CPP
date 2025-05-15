#include<iostream>
using namespace std;



void insertionsort(int a[],int n){
    
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        for(;j>=0;j--){
            if(a[j]>temp)
            a[j+1]=a[j];
            else
            break;
        }
        a[j+1]=temp;
    }
    
}
int main()
{
    int a[]={2,5,6,4,9,2,0,1,7,6};
    insertionsort(a,10);

    cout<<"sorted array "<<endl;
    for(int i=0;i<10;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}