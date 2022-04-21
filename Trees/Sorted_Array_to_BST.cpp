TreeNode* form_BST(vector<int>&nums, int l, int h) {
    if (l == h)
        return new TreeNode(nums[l]);  //if both l and h are pointing at the same position form a new node and return it
    else if (l < h) {
        int mid = l + (h - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);   //form the root of the current subtree

        root->left = form_BST(nums, l, mid - 1);  //form the left half of the BST and attach it to the
        //left of current subtree's root
        root->right = form_BST(nums, mid + 1, h);  //form the right half of the BST and attack it to the right of
        //current subtree's root
        return root;  //return the formed BST
    } else
        return NULL;  //if l > h then return NULL
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int l = 0, h = nums.size() - 1;
    return form_BST(nums, l, h);  //form_BST functions returns the root of the newly formed tree Node
}