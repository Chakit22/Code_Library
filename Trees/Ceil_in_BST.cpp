int findCeil_helper(BinaryTreeNode<int>*node, int x) {
	if (node == NULL)
		return INT_MAX;
	if (node->data >= x)
		return min(node->data, findCeil_helper(node->left, x));
	else
		return findCeil_helper(node->right, x);
}

int findCeil(BinaryTreeNode<int> *node, int x) {
	// Write your code here.
	int y;
	return ((y = findCeil_helper(node, x)) == INT_MAX ? -1 : y);
}