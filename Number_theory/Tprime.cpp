#include<bits/stdc++.h>
using namespace std;
#define ll long long


vector<ll> init() {
   int N = 1000005;
   bool sieve[N + 1];
   for (int i = 2; i <= N; ++i)
      sieve[i] = true;

   for (int i = 2; i * i <= N; ++i) {
      if (sieve[i] == true) {
         for (int j = i * i; j <= N; j += i) {
            sieve[j] = false;
         }
      }
   }
   vector<ll>tprimes;
   for (ll i = 2; i <= N; ++i) {
      if (sieve[i])
         tprimes.push_back(i * i);
   }
   return tprimes;
}

int main() {
   vector<ll>tprimes = init();
   int t;
   cin >> t;
   while (t--) {
      ll n;
      cin >> n;
      if (upper_bound(tprimes.begin(), tprimes.end(), n) - lower_bound(tprimes.begin(), tprimes.end(), n))
         cout << "YES";
      else
         cout << "NO";

      cout << "\n";
   }
}