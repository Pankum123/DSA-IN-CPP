#include<iostream>
using namespace std;

int unique_element(int *arr,int n){

    //1st method
     
    int ans=0;
    for(int i=0;i<n;i++){
         ans = ans^arr[i];
    }
    return ans;
    

   //2nd method
   //all element are positive

//    for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//         if(arr[i]==arr[j]){
//             arr[i]=arr[j]=-1;
//             break;
//         }
//     }
//    }

//    for(int i=0;i<n;i++){
//     if(arr[i]>0){
//         return arr[i];
//     }
//    }

}
int main(){
    
    int arr[8]={2,4,3,5,2,5,4};

    cout<<"unique element = "<< unique_element(arr,7) <<endl;

    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}