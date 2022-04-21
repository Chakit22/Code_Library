    int lcs(int x,int y,string &a,string &b){
        int dp[x+1][y+1];
        
        for(int i=0;i<=x;++i)
        {
            for(int j=0;j<=y;++j)
            {
                if(i==0 or j==0)
                {
                    dp[i][j] = (j==0?i:j);
                }
                else {
                    if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1];
                    else
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[x][y];
    }
  
    int editDistance(string a, string b) {
        // Code here
        int ans = lcs(a.size(),b.size(),a,b);
        return ans;
    }
