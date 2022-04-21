bool hasPathSum(Node *root, int S) {
// Your code here
if(root == NULL)
return false;

if(root->right == NULL and root->left == NULL)
return S==root->data;

return (hasPathSum(root->left,S - root->data) or hasPathSum(root->right,S - root->data));
}