#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	ll val = a[0];

	for (int i = 1; i < n; ++i) {
		val = gcd(a[i], val);
	}
	ll x = -1;
	//if gcd of the whole array is less than k itself then definitely answer is true,as you can divide the whole array by gcd itself
	//if we divide the whole array by gcd then atleast one pair in the array will be co-prime and,
	//if atleast one pair in the array is co-prime then the gcd of the whole array is one or the whole array is said to be co-prime.
	if (val <= k)
		cout << "YES";
	// if gcd of the whole array is greater than k then, list out the factors of gcd
	/*
	For ex
	if gcd of whole array is 6 and k is 4 then factors of gcd are 1,2,3,6 no we know that 2*3 = 6 and 2<=k and 3<=k
	so if the array is divided first by 2 and then by 3 then array becomes co-prime.

	but for ex
	gcd of whole array is 46 and k is 2 ,though gcd%k == 0 but gcd/2 = 23 which is greater than 2 and hence the whole array cannot be made
	co-prime.

	so, if the largest factor of the gcd of array is less than or equal to k then keep on dividing by that and the
	array becoes co-prime.
	*/
	else {
		for (int i = 2; val != 0 and i * i <= val; ++i)
		{
			if (val % i == 0) {
				x = i;
				while (!(val % i))
					val /= i;
			}
		}
		if (val > 1)
			x = val;  //if val > 1 then val is prime and highest factor of a number is that which is prime because that is the last number left in
		//the iteration while dividing by i and as i is in increasing order starting from 2 so gcd/i will be increasing till i*i where the loop exits.

		if (x <= k)
			cout << "YES";
		else
			cout << "NO";
	}

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
}