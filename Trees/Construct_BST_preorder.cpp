unordered_map<int, int> nxt_gr(vector<int> &arr, int n) {
    unordered_map<int, int>mp;
    stack<int>s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and s.top() <= arr[i])
            s.pop();
        if (s.empty())
        {
            s.push(arr[i]);
            mp[arr[i]] = -1;
            continue;
        }
        mp[arr[i]] = s.top();
        s.push(arr[i]);
    }
    return mp;
}

unordered_map<int, int> nxt_sr(vector<int> &arr, int n) {
    unordered_map<int, int>mp;
    stack<int>s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and s.top() >= arr[i])
            s.pop();
        if (s.empty())
        {
            s.push(arr[i]);
            mp[arr[i]] = -1;
            continue;
        }
        mp[arr[i]] = s.top();
        s.push(arr[i]);
    }
    return mp;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    unordered_map<int, int>ngr = nxt_gr(preorder, preorder.size());
    unordered_map<int, int>nsr = nxt_sr(preorder, preorder.size());

    TreeNode* root = new TreeNode(preorder[0]);
    TreeNode* tmp = root;
    queue<TreeNode*>q;
    q.push(root);
    unordered_set<int>st;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front();
            q.pop();

            if ((nsr[node->val] != -1) and (st.find(nsr[node->val]) == st.end()))
            {
                node->left = new TreeNode(nsr[node->val]);
                q.push(node->left);
                st.insert(nsr[node->val]);
            }

            if ((ngr[node->val] != -1) and (st.find(ngr[node->val]) == st.end()))
            {
                node->right = new TreeNode(ngr[node->val]);
                q.push(node->right);
                st.insert(ngr[node->val]);
            }
        }
    }
    return tmp;
}


//Method 2
//bound here is the upper bound
//As it is a prorder traversal,if the value is present to the left then it will be present just to the next of the cuurent
//node's value in the preorder array else it will not be present.
TreeNode *formPreOrder(vector<int> &pre, int &idx, int bound)
{
    if (idx == pre.size() || pre[idx] > bound) return NULL;
    TreeNode *root = new TreeNode(pre[idx++]);
    // if going left upper bound become the node value
    root->left = formPreOrder(pre, idx, root->val);
    // if going to right the same upper bound is transferred
    // for inserting to the right the value must be less than root's parent, nothing other to be validated.
    root->right = formPreOrder(pre, idx, bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int idx = 0;
    return formPreOrder(preorder, idx, INT_MAX);
}