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


//Method 2
bool isvalid(TreeNode* root, long lft_min, long rgt_max) {
    if (root == NULL)
        return true;
    if (root->val <= lft_min or root->val >= rgt_max)
        return false;
    return isvalid(root->left, lft_min, root->val) and isvalid(root->right, root->val, rgt_max);
}

bool isValidBST(TreeNode* root) {
    return isvalid(root, LONG_MIN, LONG_MAX);
}