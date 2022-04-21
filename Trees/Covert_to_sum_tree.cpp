//this functions actualy returns the whole sum of the tree
int tosum_helper(Node *root) {
    if (root == NULL)
        return 0;

    int sml = tosum_helper(root->left);
    int smr = tosum_helper(root->right);

    int tmp = root->data;  //takes the current value in a temp and stores the suml and sml sum at its root. As the current root node has to be changed so
    //it has to be stored in some variable.
    root->data = sml + smr;  //Changes the current root node to the sum of left and right.

    return tmp + sml + smr;  //returns the whole sub-tree sum each from the left and right. and it is replaced by the root.
}

void toSumTree(Node *root)
{
    // Your code here
    tosum_helper(root);
}