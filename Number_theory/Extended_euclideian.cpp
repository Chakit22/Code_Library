#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	} else {
		int val = gcd(b, a % b, x, y);
		int tmp = x;
		x = y;
		y = tmp - (a / b) * y;
		return val;
	}
}

int main() {
	int a, b;
	int x, y;
	cin >> a >> b;
	cout << "gcd is :" << gcd(a, b, x, y) << "\n";
	cout << "The values of x and y are ; " << "x : " << x << "  y : " << y << "\n";
}

/*
GCD value can be expressed in terms of A*x + B*y = gcd(A,B);
At each stage x and y vary and from those particular values we can calculate the gcd of those a and b in that recursive call.
*/