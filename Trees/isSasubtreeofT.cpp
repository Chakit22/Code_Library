bool isSubTree(Node* T, Node* S)
{
    // Your code here
    if (!T and !S) //if both the subtrees are null then s is a subtree of t
        return true;

    if ((!T and S) or (!S and T))  //if one of them is null then definitely ans is false
        return false;

    if (T->data == S->data) { //if the data at root is equal then check for the right and left and right subtrees
        bool lft = isSubTree(T->left, S->left);
        bool rgt = isSubTree(T->right, S->right);
        return ((lft and rgt) ? true : (isSubTree(T->left, S) or isSubTree(T->right, S)));
        //if the ans from both left and right subtrees is true then s is present in this subtree with root as root else
        //return ans from right or ans from left
    } else {
        return isSubTree(T->left, S) or isSubTree(T->right, S); //if data at root is not equal then it may happend
        //that s is a subtree of left part of T or right part of T.
    }
}