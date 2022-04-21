#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	//The approach can also be Segment tree.
	//In this the concept of prefix sum is used
	/*
	A prefix sum array can also be thought of like if some value val is to be added bewteen l and r then if a value val is
	added at index l and -val is added at r+1 th index then when prefix sum of this array is made, val will be added bewteen
	l and r,basically it can be thought of like val is made as as the base value instead of zero now till r and when some
	next value is added then the same job can be done and when prefix sum of that array is made it will add upto the base value

	for ex:-
	0 0 0 0 0 0

	q1 : 2 4 10
	arr : 0 10 0 0 -10 0
	q2 : 3 4 20
	arr : 0 10 20 0 (-10-20) 0

	prefix sum at end
	0 10 30 30 0 0
	0 10 (10+20) (10+20) 0 0  s we can see 20 is added upon the base value 10
	*/
	ll n, q;
	cin >> n >> q;
	ll a[n + 1] = {0ll};
	//intitially an array of size n with all zeroes and we've been given Q queries
	while (q--) {
		ll l, r, k;
		cin >> l >> r >> k;
		//basically we have add k in between the indices l and r and find the maximum.
		a[l] += k;
		if ((r + 1) <= n)
			a[r + 1] -= k;
	}
	//make prefix sum
	for (int i = 2; i <= n; ++i)
		a[i] += a[i - 1];
	ll max_val = 0;
	for (int i = 1; i <= n; ++i)
		max_val = max(max_val, a[i]);
	cout << max_val;
}