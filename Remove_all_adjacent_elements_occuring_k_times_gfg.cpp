#include<bits/stdc++.h>
using namespace std;
string Reduced_String(int k, string s) {
	// Your code goes here
	if (k == 1)
		return "";
	stack<pair<char, int>>st;
	string ans;
	for (auto i : s) {
		if (st.empty()) {
			st.push({i, 1});
		} else {
			if ((st.top().first == i) and (st.top().second == k - 1)) {
				st.pop();
			} else if (st.top().first == i) {
				st.top().second++;
			} else {
				st.push({i, 1});
			}
		}
	}
	while (!st.empty())
	{
		int cnt = st.top().second;
		while (cnt--)
			ans += st.top().first;

		st.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}


int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	cout << Reduced_String(k, s);
	return 0;
}
