#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int dp[n + 1];
	dp[0] = dp[1] = 0;
	int h[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> h[i];
	for (int i = 2; i <= n; ++i)
	{
		int mn_cost = INT_MAX;
		for (int jump = 1; jump <= k; ++jump)
		{
			if (i - jump > 0)
				mn_cost = min(mn_cost, abs(h[i] - h[i - jump]) + dp[i - jump]);
			else
				break;
		}
		dp[i] = mn_cost;
	}
	cout << dp[n];
}
