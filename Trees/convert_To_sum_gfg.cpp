int tosum_helper(Node *root){
    if(root == NULL)
    return 0;
    
    int sml = tosum_helper(root->left);   
    int smr = tosum_helper(root->right);
    
    int tmp = root->data;  //takes the current value in a temp and stores the suml and sml sum at its root
    root->data = sml + smr;
    
    return tmp + sml + smr;  //returns the whole sub-tree sum
}

void toSumTree(Node *root)
{
    // Your code here
    tosum_helper(root);
}