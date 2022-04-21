#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int M, int V) 
{ 
    // Your code goes here
    int dp[V+1];
    dp[0] = 0;
    for(int i=1;i<=V;++i)
    dp[i] = INT_MAX;
    
    for(int i=1;i<=V;++i)
    {
        for(int j=0;j<M;++j){
            if(i-coins[j] >= 0 and dp[i-coins[j]] != INT_MAX)
            dp[i] = min(dp[i],1 + dp[i-coins[j]]);
        }
    }
    return (dp[V] == INT_MAX ? -1:dp[V]);
} 

int main(){
	int M;
	cin>>M;
	int coins[M];
	for(int i=0;i<M;++i)
		cin>>coins[i];
	int V;
	cin>>V;

	cout<<minCoins(coins,M,V);
}
