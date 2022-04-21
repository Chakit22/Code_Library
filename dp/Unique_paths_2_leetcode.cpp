int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    int dp[rows+1][col+1];
    dp[1][1] = 1;
    for(int i=0;i<=rows;++i)
    {
        for(int j=0;j<=col;++j)
        {
            if(i==0 or j==0)
                dp[i][j] = 0;
            else{
                if(obstacleGrid[i-1][j-1] == 1)
                    dp[i][j] = INT_MAX;
                else if(i==1 and j==1)
                    continue;
                else if(dp[i-1][j] == INT_MAX or dp[i][j-1] == INT_MAX)
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return ((dp[rows][col] == INT_MAX)?0:dp[rows][col]);
}
