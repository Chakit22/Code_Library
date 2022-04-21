#include<bits/stdc++.h>
using namespace std;

int change(int amount, vector<int>& coins) {
    int n=coins.size();
    int dp[amount+1];
    for(int i=1;i<=amount;++i)
        dp[i] = 0;
    dp[0] = 1;
    for(int i=1;i<=amount;++i)
    {
        for(int j=0;j<n;++j){
        if(i-coins[j] >= 0)
            dp[i] = dp[i] + dp[i-coins[j]];
        }
    }

    return dp[amount];
}

int main(){
    int n;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;++i)
        cin>>coins[i];
    int v;
    cin>>v;
    cout<<change(v,coins);
}

//When done using recursion use Unbounded Knapsack. Basically Unbounded knapsack provides us the solution where the order does not matter;
