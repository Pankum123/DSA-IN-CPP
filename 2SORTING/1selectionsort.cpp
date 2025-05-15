#include<iostream>
using namespace std;



void selectionsort(int a[],int n){
    
    for(int i=0;i<n-1;i++){

        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(a[minindex]>a[j])
                minindex=j;
        }
       // swap(a[i],a[minindex]);
       int temp=a[minindex];
       a[minindex]=a[i];
       a[i]=temp;

    }
}
int main()
{
    int a[]={2,5,6,4,9,2,0,1,7,6};
    selectionsort(a,10);

    cout<<"sorted array "<<endl;
    for(int i=0;i<10;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}