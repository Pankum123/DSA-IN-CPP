#include<iostream>
#include<vector>
using namespace std;

// Recursion

// int tribo(int n){
//     if(n==0) return 0;
//     if(n==1 || n==2) return 1;
//     else return tribo(n-1) + tribo(n-2) + tribo(n-3);
// }

// DP with memoization

int tribo(int n,vector<int>& dp){
    if(n==0) return 0;
    if(n==1 || n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    else return dp[n] = tribo(n-1,dp) + tribo(n-2,dp) + tribo(n-3,dp);
}

// Dp with Bottom Up Solution

int tribo(int n){
    if(n==0) return 0;
    if(n==1 || n==2) return 1;
    vector<int>dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    // normal recursion
    // cout<<tribo(n);

    // DP with memoization
    // vector<int>dp(n+1,-1);
    // cout<<tribo(n,dp);             // 0, 1, 1, 2, 4, 7, 13

    // Bottom Up
    cout<<tribo(n);
    return 0;
}