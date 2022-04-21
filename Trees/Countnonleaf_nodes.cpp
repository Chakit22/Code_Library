int countNonLeafNodes(Node* root)
{
    // Code here
    if (root == NULL)
        return 0;

    if ((root->left == NULL and root->right == NULL))  //if the cuurent root node is the leaf node then in this subtree the no of non leaf nodes is zero
        return 0;

    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);  //as the current node is not a leaf node from the above if condition
    //so add 1 and caluclate the no of non leaf nodes from the left and the right and add them and return the answer.
}