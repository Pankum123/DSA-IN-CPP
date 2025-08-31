#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string decimalToBinary(long long n){
    string binary = "";

    while(n>0){
        binary += to_string(n%2);
        n /= 2; 
    }

    reverse(binary.begin(),binary.end());
    return binary;
}

int binaryToDecimal(string binary,long long m,long long mod){
    int n = binary.size();
    long long p = 1;
    long long decimal = 0;
    for(int i=n-1;i>=0;i--){
       if(binary[i]=='1'){
        decimal += p;
        decimal %= mod;
       } 
       p *= m;
       p %= mod;
    }
    return decimal;
}
void solve(){
    long long n,k;
    cin>>n>>k;
    string binary = decimalToBinary(k);
    long long ans = binaryToDecimal(binary,n,1000000007);
    cout<<ans<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}