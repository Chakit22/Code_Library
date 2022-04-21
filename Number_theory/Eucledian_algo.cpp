#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b);
}

/*
This is based on the fact that
for ex:-
Let a and b be two numbers with b>a

so, b can be written as b=(some_multiple)*a + rem
let the gcd be g

so we know that
b%g == 0 and a%g == 0

((some_multiple*a) + rem)%g = 0
which implies : - some_multiple*a + rem = n * g  ; where n is some integer

as a%g == 0
a = m*g  ; where m is an integer

some_multiple * (m*g) + rem = n*g
rem = g*(n-some_multpile*m)

whihc states that g is less than or equal to rem and is a factor of rem, so the gcd will lie in the range [1,rem].

so replace the larger number by b%a where b is the larger number and keep the other number as smallest of two.

and perform the same iterations until rem = 0 which states that at some instant b will divide a with rem = 0 and that is our gcd.
*/