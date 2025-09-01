#include<iostream>
#include<vector>
using namespace std;

// Recursion

// int fibo(int n){
//     if(n<=1) return n;
//     else return fibo(n-1) + fibo(n-2);
// }

// DP with memoization

// int fibo(int n,vector<int>& dp){
//     if(n<=1) return n;
//     if(dp[n]!=-1) return dp[n];
//     else return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
// }

// Dp with Bottom Up Solution

int fibo(int n){
    vector<int>dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    // normal recursion
    // cout<<fibo(n);

    // DP with memoization
    // vector<int>dp(n+1,-1);
    // cout<<fibo(n,dp);             // 0 1 1 2 3 5 8 13

    // Bottom Up
    cout<<fibo(n);
    return 0;
}