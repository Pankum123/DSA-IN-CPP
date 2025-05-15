#include<iostream>
using namespace std;

        //printarray
        void printarray(int arr[],int n){
            
                for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
                cout<<endl;
            }

        //raversearray
        void reversearray(int arr[],int n){
            int start=0;
            int end=n-1;
            
            while (start<=end)
            {
                swap(arr[start],arr[end]);

                // int temp=arr[start];
                //     arr[start]=arr[end];
                //     arr[end]=temp;

                start++;
                end--;
                
            }
        
    
        }

        
                
    
        int main(){
            
            int arr[5]={1,2,3,4,5};

            printarray(arr,5);
            reversearray(arr,5);
            printarray(arr,5);

            return 0;
        }