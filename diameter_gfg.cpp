int height(Node* root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int diameter(Node* root)  //this function returns the diameter of the cuurent subtree with root as root.
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int diam_sub_tree = lh + rh + 1;  //diameter of the current subtree with root as root.

    return max(diam_sub_tree, max(diameter(root->left), diameter(root->right)));  //do the same job for all of the left and right nodes.
}

//To calculate the diameter of a binary tree we consider diameter for each of the nodes in the tree and find the max from all of it.
//Including the current node the diameter of this subtree with this as the node will be 1 + height from left + height from right.