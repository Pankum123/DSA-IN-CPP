#include<iostream>
using namespace std;

    //printarray
    void printarray(int arr[],int n){
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }

      
    //largest maximum array value
    int maxarray(int arr[],int n){
    
        int maxvalue=arr[0];

        for(int i=0;i<n;i++){

           maxvalue = max(maxvalue,arr[i]);

        // if(maxvalue<arr[i])
        //     maxvalue=arr[i];
            
        }

       return maxvalue;
    }

    //lowest minimun array value
    int minarray(int arr[],int n){
    
        int minvalue=arr[0];

        for(int i=0;i<n;i++){

           minvalue = min(minvalue,arr[i]);

        // if(minvalue>arr[i])
        //     minvalue=arr[i];
            
        }

       return minvalue;
    }
   
    //2nd maximum array value
    int max2array(int arr[],int n){
    
        int maxvalue=arr[0];

        for(int i=1;i<n;i++){

        //   maxvalue = max(maxvalue,arr[i]);

        if(maxvalue<arr[i])
            maxvalue=arr[i];
            
        }

        int max2value=arr[0];
        for(int i=1;i<n;i++){

            if(max2value<arr[i]&&arr[i]!=maxvalue)
            max2value=arr[i];
        }
       
       return max2value;
    }

    //2nd minimun array value
    int min2array(int arr[],int n){
    
        int minvalue=arr[0];

        for(int i=1;i<n;i++){

        //   minvalue = min(minvalue,arr[i]);

        if(minvalue>arr[i])
            minvalue=arr[i];
            
        }

        int min2value=arr[0];
        for(int i=1;i<n;i++){

        //   min2value = min(min2value,arr[i]);

            if(min2value>arr[i] && arr[i]!=minvalue)
                min2value=arr[i];
            
        }
        
       return min2value;
    }
   
    
   
    int main(){

        int arr[6]={4,18,2,11,9,7};

        printarray(arr,6);
        
        cout<<"largest value= "<<maxarray(arr,6)<<endl;
        cout<<"minimum value= "<<minarray(arr,6)<<endl;
        cout<<"2nd larest value = "<<max2array(arr,6)<<endl;
        cout<<"2nd minimum value = "<<min2array(arr,6)<<endl;

        
    return 0;
    }