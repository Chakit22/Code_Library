void preorder(Node* root,map<int,int>&m,int level){
    if(root == NULL)
    return;
    
    if(m.find(level) == m.end())
    m[level] = root->data;
    
    preorder(root->right,m,level+1);
    preorder(root->left,m,level+1);
}


vector<int> rightView(Node *root)
{
   // Your code here
   map<int,int>m;
   vector<int>ans;
   preorder(root,m,0);
   for(auto i:m)
   ans.pb(i.second);
   return ans;
}