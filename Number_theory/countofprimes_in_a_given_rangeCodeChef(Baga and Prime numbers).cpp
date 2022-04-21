#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1000005;  //considering the fact that max value of r is 10^12 so max value of sieve array will be sqrt(10^12) .i.e. 10^6
bool sieve[N+1];

ll max(ll a,ll b){
	if(a<b)
		return b;
	else
		return a;
}

void create_sieve(){
	for(int i=2;i<=N;++i)
		sieve[i] = true;  //mark all the numbers as true considering they are prime

	for(int i=2;i*i<=N;++i){
		if(sieve[i] == true){  //do this job only if sieve[i] is true because this a possible prime number,those marked as false are not prime.
			for(int j=i*i;j<=N;j += i){ //start from i*i for ex 5*5 is better to start rather than 5*2 as 2*5 is already marked false by 2 so no need to srat from 5*2 again.
				sieve[j] = false;
			}
		}
	}
}

vector<int> generate_primes(int n){
	vector<int>primes;
	for(int i=2;i<=n;++i)
	{
		if(sieve[i] == true)
			primes.push_back(i);
	}
	return primes;
}

int main(){
	create_sieve();
	int t;
	cin>>t;
	while(t--){
		ll l,r;
		cin>>l>>r;

		//step 1 To generate all primes till sqrt(r)
		//O(10^6)
		vector<int>primes = generate_primes(sqrt(r)+2);

		//step 2
		//create a dummy array of size r-l+1
		bool dummy[r-l+1];
		for(int i=0;i<r-l+1;++i)
		dummy[i] = true;

		//step 3 
		//iterate on dummy array and mark elements in this range l to r as false which are not prime
		for(int i=0;i<primes.size();++i){
			int pr = primes[i];
			ll first_multiple = (l/pr)*pr;  //find out the first multiple of the primes numbers in this range to start the sieve.
			if(first_multiple < l)
				first_multiple += pr;  //if first multiple is less then l then definetly next multiples will bre greater than l

			for(ll itr = max(first_multiple,(ll)pr*pr);itr <=r;itr += pr){  //itr starts from max(first_muliplt,pr*pr)  as for ex if l is 110 and r is 130 and pr is 11 
				//so first multiple will store (110/11)*11 which is 110 and is already marked false by 2 so no need to iterate on that. so start from pr*pr as in the case of sieve. 
				dummy[itr-l] = false;
			}
		}

		//step 4 printing all the prime numbers
		ll cnt=0;
		for(int i=0;i<r-l+1;++i)
		{
		    if(i+l == 1)
		    continue;
		    if(dummy[i] == true)
		    cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}