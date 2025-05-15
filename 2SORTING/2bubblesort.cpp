#include<iostream>
using namespace std;



void bubblesort(int a[],int n){
    for(int i=1;i<n;i++){
        bool swapped=false;
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            // int temp=a[j];
            // a[j]=a[j+1];
            // a[j+1]=temp;
            swapped=true;
            }
        }
        if(swapped==false)
        break;
    }
    
}
int main()
{
    int a[10]={2,5,6,4,9,2,0,1,7,6};
    bubblesort(a,10);

    cout<<"sorted array "<<endl;
    for(int i=0;i<10;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}