#include<bits/stdc++.h>
using namespace std;
#define ll long long

void swap(ll &a, ll &b) {
	ll x = a;
	a = b;
	b = x;
}

void arrange(ll a[], int n) {
	for (int i = 0; i < n; ++i) {
		while (a[i] != i and a[i] != -1)
			swap(a[i], a[a[i]]);
	}
}

void print_arr(ll a[], int n) {
	for (int i = 0; i < n; ++i)
		cout << a[i] << "   ";

	cout << "\n";
}

int main() {
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	arrange(a, n);
	print_arr(a, n);
}