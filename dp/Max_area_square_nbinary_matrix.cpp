int maximalSquare(vector<vector<char>>& matrix) {
    int rows=matrix.size();
    int col=matrix[0].size();
    int dp[rows][col];
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<col;++j)
            dp[i][j] = matrix[i][j] - '0';
    }
    int max_area=0;
    
    for(int i = 0;i<rows;++i){
        for(int j = 0;j<col;++j){
            
            if(i==0 or j==0);
            else if(dp[i][j] != 0)
            dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
            
            max_area = max(max_area,dp[i][j]);
        }
    }
    return max_area * max_area;
} 
