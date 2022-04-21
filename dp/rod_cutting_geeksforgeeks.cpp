#include<bits/stdc++.h>
using namespace std;

int dp[10000];
int rod_cut(int price[],int n){
	if(n==0)
		return 0;

	if(dp[n]!=-1)
		return dp[n];

	int cost = 0;
	for(int cut=1;cut<=n;++cut){
		cost = max(cost,price[cut] + rod_cut(price,n-cut));
	}
	return dp[n] = cost;
}

int main(){
	for(int i=0;i<10000;++i)
		dp[i] = -1;
	int n;
	cin>>n;
	int price[n];
	for(int i=0;i<n;++i){
		cin>>price[i];
	}

	cout<<rod_cut(price,n);
}
