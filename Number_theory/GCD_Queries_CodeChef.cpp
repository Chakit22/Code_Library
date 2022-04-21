#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

vector<int> init_left(int a[], int n) {
	vector<int>gcd_left(n + 1);
	gcd_left[1] = a[1];
	for (int i = 2; i <= n; ++i)
	{
		gcd_left[i] = gcd(gcd_left[i - 1], a[i]);
	}
	return gcd_left;
}

vector<int> init_right(int a[], int n) {
	vector<int>gcd_right(n + 1);
	gcd_right[n] = a[n];
	for (int i = n - 1; i > 0; --i)
	{
		gcd_right[i] = gcd(gcd_right[i + 1], a[i]);
	}
	return gcd_right;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		int a[n + 1];
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		vector<int>gcd_left = init_left(a, n);
		vector<int>gcd_right = init_right(a, n);
		while (q--) {
			int l, r;
			cin >> l >> r;
			if (l - 1 <= 0)
				cout << gcd_right[r + 1];
			else if (r + 1 > n)
				cout << gcd_left[l - 1];
			else {
				cout << gcd(gcd_left[l - 1], gcd_right[r + 1]);
			}
			cout << "\n";
		}
	}
}