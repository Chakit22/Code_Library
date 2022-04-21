#define pb push_back
int kthAncestor(Node *root, int k, int node)
{
    unordered_map<int, int>parent;
    parent[root->data] = -1;
    queue<Node*>q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            Node* node_ = q.front();
            q.pop();
            if (node_->left != NULL)
            {
                q.push(node_->left);
                parent[node_->left->data] = node_->data;
            }

            if (node_->right != NULL)
            {
                q.push(node_->right);
                parent[node_->right->data] = node_->data;
            }
        }
    }
    int p = node;
    int ancestor = k - 1;
    while (parent[p] != -1 and ancestor)
    {
        p = parent[p];
        ancestor--;
    }
    return parent[p];
}