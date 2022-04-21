#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int dp[n + 1];
	int h[n + 1];
	h[0] = INT_MIN; //this is inititalized as INT_MIN so that when end =2 then end-2 will be 0 so as h[0] will store INT_MIN any value
	for (int i = 1; i <= n; ++i)
		cin >> h[i];
	dp[0] = dp[1] = 0;  //to reach 1 from 1 or to reach 0 from 1 ans is always 0;

	for (int end = 2; end <= n; ++end)
		dp[end] = min(abs(h[end] - h[end - 1]) + dp[end - 1], abs(h[end] - h[end - 2]) + dp[end - 2]);
	cout << dp[n]; //this will store the minimum cost to reach n from staring index 1
}
