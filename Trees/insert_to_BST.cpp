#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->data = val;
        left = right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL)
        return new TreeNode(key);  //if node is null then definitely this will be the right position to insert
    //the new node with key as data.

    if (key > root->data)
        root->right = insert(root->right, key);
    else
        root->left = insert(root->left, key);
    return root;
}

void printBST(TreeNode* root) {
    if (root == NULL)
        return;
    printBST(root->left);
    cout << root->data << "  ";
    printBST(root->right);
}

int main() {
    int nodes;
    cin >> nodes;
    TreeNode* root = NULL;
    for (int i = 0; i < nodes; i++)
    {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    printBST(root);
    cout << "\n";
    return 0;
}