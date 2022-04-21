    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>v;
        v.push_back(1);
        ans.push_back(v);
        
        for(int i=1;i<numRows;++i){
            vector<int>v;
            v.push_back(1);
            for(int j=1;j<=i;++j){
                v.push_back(j == ans[i-1].size() ? ans[i-1][j-1] : ans[i-1][j-1] + ans[i-1][j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
