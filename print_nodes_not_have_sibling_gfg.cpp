void find_siblings(Node *root,vector<int>&ans){
    if(root == NULL)
    return;
    
    if(root->left == NULL and root->right != NULL)
    ans.push_back(root->right->data);
    else if(root->left != NULL and root->right == NULL)
    ans.push_back(root->left->data);
    
    find_siblings(root->left,ans);
    find_siblings(root->right,ans);
}

vector<int> noSibling(Node* node)
{
    // code here
    vector<int>ans;
    find_siblings(node,ans);
    sort(ans.begin(),ans.end());
    if(ans.size() == 0)
    {
        ans.push_back(-1);
        return ans;
    }
    return ans;
}