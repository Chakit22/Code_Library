//The ans for each level is calculated as the index of first non-empty node from the last - 
//index of the first non-empty node from the first

int level_order(TreeNode * root){
    int max_width = 1;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int sz = q.size();
        int min_idx = q.front().second;  //in each of the levels the first non_empty() node will 
                                         //have the smallest index
        int first,last;
        for(int i=0;i<sz;++i){
            auto node = q.front();
            q.pop();
            int cur_idx = node.second - min_idx;   
//we try to make the indexing as 1,2,...
//so here we subtract them with min values of indices so that it becomes 0,1,2... which is
//the upper level indexing we needed. 
//To achieve this we need the upper levl's indexing as 0,1,2...so that this 
//can 2*(upper_level_index) + 1 for left node
//and 2*upper_level_index + 2 for the right guy    
            if(i==0)
            first = cur_idx;  //This makes the zero based indexing as it is stor
            if(i==sz-1)
            last = cur_idx;
            if((node.first)->left)
            q.push({node.first->left,2ll*cur_idx + 1});
            if((node.first)->right)
            q.push({node.first->right,2ll*cur_idx + 2});
        }
        max_width = max(max_width,last-first + 1);
    }
    return max_width;
}

int widthOfBinaryTree(TreeNode* root) {
    return level_order(root);
}

//For one based indexing for the left node 2*upper_level_index and for the 
//right node 2*upper_level_index + 1.and for zero as mentioned in the above code.