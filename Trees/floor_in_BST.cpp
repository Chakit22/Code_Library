int floor_helper(TreeNode<int>*root, int x) {
	if (root == NULL)
		return INT_MIN;
	if (root->data > x)
		return floor_helper(root->left, x);
	else
		return max(root->data, floor_helper(root->right, x));
}

int floorInBST(TreeNode<int> * root, int x)
{
	// Write your code here.
	int y;
	return ((y = floor_helper(root, x)) == INT_MIN ? -1 : y);
}