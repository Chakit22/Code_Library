#include<bits/stdc++.h>
using namespace std;

void build(vector<int>&tree, int lt, int ht, int a[], int index) {
	//build function actually updates the value at index of tree as sum from range lt to ht with respect to arr indices.
	if (lt > ht)
		return;  //nothing to be updated
	if (lt == ht)
	{
		tree[index] = a[lt];  //merges at single element present at index lt
		return;
	}
	int mid = lt + (ht - lt) / 2;
	//value at any index is sum of left values and right ones.
	build(tree, lt, mid, a, 2 * index + 1);
	build(tree, mid + 1, ht, a, 2 * index + 2);
	tree[index] = tree[2 * index + 1] + tree[2 * index + 2]; //current indices value stored at tree[index]  left indice is 2*index+1 and right one 2*index+2
}

void print_tree(vector<int>&tree) {
	int idx = 0;
	while (tree[idx] != INT_MIN)
	{
		cout << "	idx : " << idx << "	tree[idx] : " << tree[idx] << "  ";
		idx++;
	}
	cout << "\n";
}

int query_sum(vector<int>&tree, int lt, int ht, int l, int h, int index) {
	if ((lt > ht) or (h<lt or l>ht)) //don't overlap then sum will be zero
		return 0;
	if (l <= lt and h >= ht)
		return tree[index];  //return complete answer if that range fully is included in that
	int mid = lt + (ht - lt) / 2;
	return query_sum(tree, lt, mid, l, h, 2 * index + 1) + query_sum(tree, mid + 1, ht, l, h, 2 * index + 2);  //current ans will be ans from left
	//child plus ans from right child.
}

void update(vector <int> &tree, int lt, int ht, int i, int val, int index) {
	if (lt > ht)
		return;  //dont update anything
	if (lt == ht) {
		tree[index] = val;
		return;   // the function is written in a such a way that when lt == ht then we have reached the leaf node wholes index is i.
	}

	int mid = lt + (ht - lt) / 2;
	if (i <= mid)
		update(tree, lt, mid, i, val, 2 * index + 1); //just update in the left half not the right half
	else
		update(tree, mid + 1, ht, i, val, 2 * index + 2);

	tree[index] = tree[2 * index + 1] + tree[2 * index + 2];   //as we are going in bottom up manner the children will be updated first and then the parent.
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int>tree(4 * n, INT_MIN);
	build(tree, 0, n - 1, a, 0);
	print_tree(tree);
	int q;
	cin >> q;
	//type 1 query for range sum
	//type 2 query for update
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			cout << query_sum(tree, 0, n - 1, l, r, 0);
		} else {
			int index, val;
			cin >> index >> val;
			update(tree, 0, n - 1, index, val, 0);
		}
	}
	return 0;
}
