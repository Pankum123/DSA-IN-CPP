#include<iostream>
#include<vector>
using namespace std;

int climbSteps(int n,vector<int>& dp){  // moves 1 step or 2 step
      if(n==0 || n==1) return 1;
      if(dp[n]!=-1) return dp[n];
      else return dp[n] = climbSteps(n-1,dp) + climbSteps(n-2,dp);
}

int climbSteps3(int n,vector<int>& dp){
    
    if(n==0) return 1;
    // if(n==1 || n==2) return n;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    else return dp[n] = climbSteps3(n-1,dp) + climbSteps3(n-2,dp) + climbSteps3(n-3,dp);
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    // cout<<climbSteps(n,dp);
    cout<<climbSteps3(n,dp);
    return 0;
}