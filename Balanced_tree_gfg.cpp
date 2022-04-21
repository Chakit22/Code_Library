int check_balanced(Node* root){
    if(root == NULL)
    return 0;  //if root is NULL height is 0
    
    int lh = check_balanced(root->left);
    int rh = check_balanced(root->right);
    
    if(lh == -1 or rh == -1)
    return -1;
    
    if(abs(lh-rh) > 1)
    return -1;
    
    return max(lh,rh) + 1;  //if both the above conditions are false then 
                            //this subtree is a balanced tree so return it's correct height.  
}

bool isBalanced(Node * root){
    //check_balanced will return the height of the tree if it is balanced else return -1
    return (check_balanced(root) == -1?false:true);
}