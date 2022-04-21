int Solution::minPathSum(vector<vector<int> > &A) {
    int rows = A.size();
    int col = A[0].size();

    int dp[rows+1][col+1];
    for(int i=0;i<=col;++i)
    dp[0][i] = INT_MAX;

    for(int j=0;j<=rows;++j)
    dp[j][0] = INT_MAX;

    dp[1][0] = 0;

    for(int i=1;i<=col;++i)
    dp[1][i] =  A[0][i-1] + dp[1][i-1];

    for(int i=2;i<=rows;++i)
    {
        for(int j=1;j<=col;++j)
        {
            dp[i][j] = A[i-1][j-1] + min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[rows][col];
}
