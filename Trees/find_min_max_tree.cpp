//the above two functions calculate the maximum and minimum of the current subtree with root as root node.

int findMax(Node *root)
{
    //code here
    if (root == NULL)
        return INT_MIN;  //INT_MIN is the maximum value if root is null
    //return answer from the three possible choices
    return max(root->data, max(findMax(root->left), findMax(root->right)));  //either root is the maximum or the answer from left or right subtree.
}
int findMin(Node *root)
{
    //code here
    if (root == NULL)
        return INT_MAX;  //INT_MAX is the minimum value if root is null
    //return answer from the three possible choices
    return min(root->data, min(findMin(root->left), findMin(root->right)));
}