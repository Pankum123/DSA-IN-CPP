#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    int c = 0;
    while(n>0){
        n /= 2;
        c++;
    }
    int ans = (1<<(c-1))-1;
    cout<<ans<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}