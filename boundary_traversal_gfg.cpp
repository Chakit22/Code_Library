void left_boundary(Node * root,vector<int>&ans){
    if(!root or (!(root->left)) and !(root->right))
    return;
    
    ans.push_back(root->data);
    if(root->left)
    left_boundary(root->left,ans);
    else
    left_boundary(root->right,ans);
}

void leaf(Node* root,vector<int>&ans){
    if(!root)
    return;
    
    if(!(root->left) and !(root->right))
    ans.push_back(root->data);
    
    leaf(root->left,ans);
    leaf(root->right,ans);
}

void right_boundary(Node * root,vector<int>&ans){
    if(!root or (!(root->left)) and !(root->right))
    return;
    
    if(root->right)
    right_boundary(root->right,ans);
    else
    right_boundary(root->left,ans);
    
    ans.push_back(root->data);
}

vector <int> boundary(Node *root)
{
    vector<int>ans;
    ans.push_back(root->data);
    left_boundary(root->left,ans);
    leaf(root,ans);
    right_boundary(root->right,ans);
    if(root->left == NULL and root->right == NULL)
    ans.pop_back();
    return ans;
}