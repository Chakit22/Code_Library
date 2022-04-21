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

bool check_pairwise_coprime(int a[], int n) {
	unordered_set<int>factors;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		while (x != 1) {
			int spf = sieve[x];
			if (factors.find(spf) != factors.end())
				return false;
			factors.insert(spf);
			while (x % spf == 0)
				x /= spf;
		}
	}
	return true;
}

int main() {
	init();
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cout << ((check_pairwise_coprime(a, n) == false) ? "no" : "yes");
	return 0;
}