bool check(TreeNode* root, TreeNode* &prev) {
    if (root == NULL)
        return true;

    if (!check(root->left, prev))
        return false;
    if (prev != NULL and prev->val >= root->val)
        return false;
    prev = root;

    if (!check(root->right, prev))
        return false;
    return true;
}

bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    return check(root, prev);
}