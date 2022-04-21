#include<bits/stdc++.h>
using namespace std;
#define ll long long
int M = 1000000007;

ll powermod(ll a, ll b) {
	if (b == 0)
		return 1ll;
	ll tmp = powermod(a, b / 2);
	tmp = (tmp % M * tmp % M) % M;

	if (b % 2)
		tmp = (tmp % M * (a % M)) % M;
	return tmp;
}

int main() {
	ll a, b;
	cin >> a >> b;
	cout << powermod(a, b);
}