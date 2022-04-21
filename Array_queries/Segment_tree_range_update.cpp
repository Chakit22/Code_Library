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
		cout << "	idx : " << idx << "	tree[idx] : " << tree[idx] << "\n";
		idx++;
	}
	cout << "\n";
}

int query_sum(vector<int>&tree, vector<int>&lazy, int lt, int ht, int l, int h, int index) {
	if (lt > ht)
		return 0;

	if (lazy[index] != 0) {
		tree[index] += lazy[index] * (ht - lt + 1); //add the lazy updates to the current node
		lazy[2 * index + 1] += lazy[index]; //pass onto it's children.
		lazy[2 * index + 2] += lazy[index];
		lazy[index] = 0;  //make the lazy update at this node as 0 as it's already added onto the node.
	}

	if (h<lt or l>ht) //don't overlap then sum will be zero
		return 0;

	if (l <= lt and h >= ht)
		return tree[index];  //return complete answer if that range fully is included in that.and this node will be updated
	//as the this condition follows after the previous if conditon.
	int mid = lt + (ht - lt) / 2;
	return query_sum(tree, lazy, lt, mid, l, h, 2 * index + 1) + query_sum(tree, lazy, mid + 1, ht, l, h, 2 * index + 2); //current ans will be ans from left
	//child plus ans from right child.
}

void range_update(vector <int> &tree, vector<int>&lazy, int lt, int ht, int l, int h, int x, int index) { //update function adds the value of x to each node
	if (lt > ht)
		return;

	if (lazy[index] != 0) {
		tree[index] += lazy[index] * (ht - lt + 1); //add the lazy updates to the current node
		lazy[2 * index + 1] += lazy[index]; //pass onto it's children.
		lazy[2 * index + 2] += lazy[index];
		lazy[index] = 0;  //make the lazy update at this node as 0 as it's already added onto the node.
	}

	//between the indices l to h
	if (l > ht or h < lt)
		return;  //don't update anything

	if (l <= lt and h >= ht) {
		//as it's lazy update is already done so we should only add x to this node
		tree[index] += x * (ht - lt + 1);
		lazy[2 * index + 1] += x;
		lazy[2 * index + 2] += x;
		//no need to write lazy[index] = 0 as it's already done in the previous if condition.
	} else {
		//it partially overlaps
		int mid = lt + (ht - lt) / 2;
		range_update(tree, lazy, lt, mid, l, h, x, 2 * index + 1); //this will update it's left child nodes
		range_update(tree, lazy, mid + 1, ht, l, h, x, 2 * index + 2); //this will update it's right children nodes
		tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
	}
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int>tree(4 * n, INT_MIN), lazy(4 * n, 0);
	build(tree, 0, n - 1, a, 0);
	// print_tree(tree);
	// exit(0);
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
			cout << query_sum(tree, lazy, 0, n - 1, l, r, 0) << "\n";
		} else {
			int l, r, x;
			cin >> l >> r >> x;
			range_update(tree, lazy, 0, n - 1, l, r, x, 0);
			// print_tree(tree);
		}
	}
	return 0;
}
