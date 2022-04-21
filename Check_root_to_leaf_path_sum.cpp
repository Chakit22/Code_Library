bool hasPathSum(Node *root, int S) {
    // Your code here
    if (root == NULL)
        return false;  // as the sum cannot be zero and the no of nodes are greater than 0 so it returns false;

    if (root->right == NULL and root->left == NULL)  //if the current node is a leaf node then return true if the sum is same as root->data
        return S == root->data; //else return false as this subtree with root as root won't contain sum as S.as no nodes below it.

    return (hasPathSum(root->left, S - root->data) or hasPathSum(root->right, S - root->data)); //if we get the sum either from the left or right return true.
}