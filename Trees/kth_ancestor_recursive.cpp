void kthancestor_helper(Node* root, bool &found, int &k, int node, int &ans) {
    if (root == NULL)
        return;
    if (root->data == node) {
        found = true;
        if (k == 0) {
            ans = root->data;
            k--;
            return;
        }
        k--;
        return;
    }

    kthancestor_helper(root->left, found, k, node, ans);
    if (found) {
        if (k == 0) {
            ans = root->data;
            k--;
            return;
        }
        k--;
        return;
    }
    kthancestor_helper(root->right, found, k, node, ans);
    if (found) {
        if (k == 0) {
            ans = root->data;
            k--;
            return;
        }
        k--;
        return;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    bool found = false;
    kthancestor_helper(root, found, k, node, ans);
    return ans;
}