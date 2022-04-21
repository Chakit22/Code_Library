#include<bits/stdc++.h>
using namespace std;
int sieve[1000005];

void init() {
	int N = 1000005;
	for (int i = 0; i < N; ++i)
		sieve[i] = i;

	for (int i = 2; i * i < N; ++i) {
		if (sieve[i] == i) {
			for (int j = i * i; j < N; j += i) {
				if (sieve[j] == j)
					sieve[j] = i;
			}
		}
	}
}

int main() {
	init();
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	//iterate on array and cancel out common prime factors
	bool vis[n] = {0};  //visited array which becomes true if any two of the values in the array have a commom prime factor
	unordered_map<int, int>mp; //stores the smallest prime factor with its indices as value
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		while (x != 1) {
			int spf = sieve[x];
			if (mp.find(spf) != mp.end()) {  //if the spf is already present then definitely these two are'nt co-prime and both of these numbers
				//which have common prime factors as spf must be marked visited.
				vis[mp[spf]] = true;
				vis[i] = true;
			} else
				mp[spf] = i;  //else store the spf with their index as value

			while (x % spf == 0)
				x /= spf;
		}
	}
	int flag = true;
	for (int i = 0; i < n; ++i)
	{
		if (!vis[i]) {
			flag = false;
			break;
		}
	}

	if (!flag)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}