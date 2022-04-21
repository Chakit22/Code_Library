// the below function returns the maximum sum from the current root node to leaf and just takes the maximum from the two possible choices.
int maxPathSum(Node* root)
{
    //code here
    if (root == NULL)
        return 0;

    return (root->data + max(/* This call does the same for left subtree
    */maxPathSum(root->left),/*This does the same for right subtree of current root node.*/ maxPathSum(root->right)));  //include the current root node and
    //return the maximum either from
    //left or right subtree.
    //As i have to calculate the maximum path sum from root to leaf i have to add root->data into my answer.
}
