#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string decimalToBinary(int n){
    string binary = "";

    while(n>0){
        binary += to_string(n%2);
        n /= 2; 
    }

    reverse(binary.begin(),binary.end());
    return binary;
}

int binaryToDecimal(string binary){
    int n = binary.size();
    int p = 1;
    int decimal = 0;
    for(int i=n-1;i>=0;i--){
       if(binary[i]=='1') decimal += p;
       p *= 2;
    }
    return decimal;
}
int main(){
    int n;
    cin>>n;
    string binary = decimalToBinary(n);
    cout<<binary<<"\n";
    
    cout<<binaryToDecimal(binary);
    return 0;
}