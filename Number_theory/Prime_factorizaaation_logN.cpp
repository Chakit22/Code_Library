#include<bits/stdc++.h>
using namespace std;
int sieve[10000005];

void init() {
	int N = 10000005;
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
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		while (n != 1) {
			cout << sieve[n] << "  ";
			n /= sieve[n];
		}
		cout << "\n";
	}
}