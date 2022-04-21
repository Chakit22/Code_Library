#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;

	Node(int val) {
		data = val;
		left = right = NULL;
	}
};
void level_order(Node *root) {
	queue<Node*>levels;
	levels.push(root);

	while (!levels.empty()) {
		int sz = levels.size();
		for (int i = 0; i < sz; ++i) {
			Node* node = levels.front();
			levels.pop();

			cout << node->data << "  ";
			if (node->left != NULL)
				levels.push(node->left);
			if (node->right != NULL)
				levels.push(node->right);
		}
	}
	cout << "\n";
}

Node* insertNode(Node* root, int item) {
	if (root == NULL) {
		return new Node(item);
	}

	int choice;
	cout << "Enter 1 to insert to the left : \n";
	cout << "Enter 2 to insert to the right : \n";
	cin >> choice;

	if (choice == 1) {
		root->left = insertNode(root->left, item);
	} else
		root->right = insertNode(root->right, item);

	return root;
}

int symmetric(Node* left, Node* right) {
	if (!left and !right)
		return 0;

	if (!left or !right or (left->data != right->data))
		return -1;

	int lft = symmetric(left->left, right->right);
	int rgt = symmetric(left->right, right->left);

	if (lft == -1 or rgt == -1)
		return -1;

	return 1 + lft;
}

int main() {
	int n;
	cout << "Enter the number of nodes : \n";
	cin >> n;
	Node* root = NULL;
	for (int i = 0; i < n; ++i) {
		int item;
		cout << "Enter the data \n";
		cin >> item;
		root = insertNode(root, item);
	}
	// cout<<"level order : ";
	// level_order(root);
	int ans;
	cout << ((ans = symmetric(root->left, root->right)) == -1 ? 1 : 1 + ans);
}
