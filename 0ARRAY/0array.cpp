#include<iostream>
using namespace std;
int main(){

    int arr1[5]={1,2,3,4,5};
    int arr2[5];

    cout<<"1st array "<<endl;

    cout<<"size of array in byte = "<<sizeof(arr1)<<endl;
    cout<<"size of array (number of element) = "<<sizeof(arr1)/sizeof(int)<<endl;

    // for each loop
    for(int ele:arr1){
        cout<<ele<<" ";
    }
    cout<<endl;
    cout<<"2nd array "<<endl;

    cout<<"enter a element in array 2 "<<endl;
    for(int ele:arr2){
        cin>>ele;
    }
      for(int ele:arr2){
        cout<<ele<<" ";
    }

    cout<<endl;
    
      for(int &ele:arr1){
        cout<<ele<<" ";
    }
    


return 0;
}