#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mx = 1000000000000000005ll;

ll ncr(int n, int k)
{
	ll C[n + 1][k + 1];
	int i, j;

	// Caculate value of Binomial Coefficient
	// in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= min(i, k); j++)
		{
			// Base Cases
			if (j == 0 || j == i)
				C[i][j] = 1;

			// Calculate value using previosly
			// stored values
			else
				C[i][j] = C[i - 1][j - 1] +
				          C[i - 1][j] + 0ll;
		}
	}
	return C[n][k];
}

int start(ll starts[], int strt, ll l_1, ll rank, int sz) {
	starts[0] = 0;
	for (int i = 1; i < sz; ++i)
	{
		starts[i] = starts[i - 1] + ncr(strt - i + 1, l_1);
	}

	// for (int i = 0; i < sz; ++i)
	// 	cout << starts[i] << "   ";
	// cout << "\n";
	int idx = lower_bound(starts, starts + sz, rank) - starts - 1;
	return idx;
}

void find_string(ll rank, vector<string>v, int n) {
	//printing
	// for (int i = 0; i < n; ++i)
	// 	cout << v[i] << "   ";
	// cout << endl;

	//step 1
	//Make an array of 1 based indexing storing values of nc1,nc2,....ncn;
	//Make that array as prefix sum
	vector<ll> prefixsum;
	prefixsum.push_back(1ll);
	for (int i = 1; i <= n; ++i)
	{
		ll cur_val = ncr(n, i);
		prefixsum.push_back(prefixsum[i - 1] + cur_val + 0ll);
		if (prefixsum[i] > mx)
			break;
	}
	//printing prefixsum
	// for (int i = 0; i < prefixsum.size(); ++i)
	// 	cout << prefixsum[i] << "   ";
	// cout << endl;

	ll len = lower_bound(prefixsum.begin(), prefixsum.end(), rank) - prefixsum.begin();
	// cout << "len  : " << len << "\n";

	//step 2 fiding rank in length an the starting index
	ll rank_in_len = rank - prefixsum[len - 1];
	// cout << "rank _ in _ len :  " << rank_in_len << "\n";
	ll l_1 = len - 1;
	// cout << "l_!  : " << l_1 << "\n";
	ll starts[n - l_1 + 1];
	int startin_idx = start(starts, n - 1, l_1, rank_in_len, n - l_1 + 1);
	ll cur_rank = rank_in_len - starts[startin_idx];
	// cout << "cur_Rank  :  " << cur_rank << "\n";

	//step 3
	//just iterate in v to find the string
	// cout << "starting _ idx : " << startin_idx << "\n";
	string ans;
	ans += (v[startin_idx] + ",");
	len--;
	int idx = startin_idx + 1;
	int end = v.size() - 1;
	while (len >= 1) {
		ll val = ncr(end - idx, len - 1);
		if (cur_rank <= val)
		{
			//include
			ans += (v[idx] + ",");
			len--;
		} else {
			cur_rank -= val;
		}
		idx++;
	}
	ans.pop_back();
	cout << ans;
}

vector<string> parse_string(string &str) {
	vector<string> v;
	stringstream ss(str);

	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		v.push_back(substr);
	}
	return v;
}

int main() {
	int N;
	ll rank;
	cin >> N;
	cin >> rank;
	string s;
	cin >> ws;
	getline(cin, s);
	vector<string>str = parse_string(s);
	int n = str.size();
	// for (int i = 0; i < n; ++i)
	// 	cout << str[i] << "   ";
	find_string(rank, str, n);
}