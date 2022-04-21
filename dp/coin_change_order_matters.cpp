#include<bits/stdc++.h>
using namespace std;

int change(int amount, vector<int>& coins) {
    int n=coins.size();
    int dp[amount+1];
    for(int i=1;i<=amount;++i)
        dp[i] = 0;

    dp[0] = 1;
        for(int j=0;j<n;++j)
        {
            for(int i=1;i<=amount;++i){
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

//In this a normal recursive function without unbounded knapsack can be employed. Unbounded knapsack won't work here as it works in the cases only when the order does not matter.
