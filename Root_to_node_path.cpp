void preorder(TreeNode* root,vector<int>&ans,vector<int>tmp_ans,int B){
    if(root == NULL)
    return;

    tmp_ans.push_back(root->val);
    if(root->val == B){
        ans = tmp_ans;
        return;
    }
    preorder(root->left,ans,tmp_ans,B);
    //After returning from the above call as the tmp_ans gets allocated
    //a new memory in stack frame everytime the topmost stack frame gets
    //popped so the last emenet inserted also gets popped as it was not
    //present in the current stack frame.
    preorder(root->right,ans,tmp_ans,B);
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    vector<int>tmp_ans;
    preorder(A,ans,tmp_ans,B);
    return ans;
}
