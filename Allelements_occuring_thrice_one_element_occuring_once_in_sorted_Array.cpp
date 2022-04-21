#include<bits/stdc++.h>
using namespace std;

int find_once(int a[], int l, int h) {
	if (l <= h) {
		int md = l + (h - l) / 2;
		int end_idx = md, start_idx = md;
		while (start_idx >= l and a[start_idx] == a[md])
			start_idx--;
		while (end_idx <= h and a[end_idx] == a[md])
			end_idx++;
		start_idx++;
		end_idx--;
		if (start_idx == end_idx)
			return a[md];
		else if (end_idx % 3 == 0)
			return find_once(a, end_idx + 1, h);
		else
			return find_once(a, l, start_idx - 1);
	}
}

int main() {
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	cout << find_once(a, 1, n);
}