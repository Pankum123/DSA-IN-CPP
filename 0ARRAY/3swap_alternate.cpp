#include<iostream>
using namespace std;

void printarray(int arr[],int n){
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap_alternate(int arr[],int n){
    
        for(int i=0;i<n;i+=2){
            if(i<n-1){
              swap(arr[i],arr[i+1]); 
            } 
    }
    
}
int main(){

    int even[6]={1,2,3,4,5,6};
    int odd[5]={1,2,3,4,5};

    swap_alternate(even,6);
    swap_alternate(odd,5);

    printarray(even,6);
    printarray(odd,5);
   
return 0;
}