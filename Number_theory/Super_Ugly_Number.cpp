#include<bits/stdc++.h>
using namespace std;
int N = 10000000;
int sieve[10000000];


void init() {
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

	for (int i = 2; i < 100; ++i)
		cout << "spf" << "[" << i << "]   " << sieve[i] << "\n";
}

int main() {
	init();
}