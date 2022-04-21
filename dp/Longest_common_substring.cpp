    int dp[1005][1005];
    int lcsub(int n,int m,int cur_l,string &s1,string &s2){
        if(n==0 or m==0)
        return cur_l;
        
        if(dp[n][m]!=-1)
        return dp[n][m];
        
        int cnt_1 = cur_l;
        if(s1[n-1] == s2[m-1])
        dp[n][m] = cnt_1 = lcsub(n-1,m-1,cur_l+1,s1,s2);
        
        return dp[n][m] = max(cnt_1,max(lcsub(n-1,m,0,s1,s2),lcsub(n,m-1,0,s1,s2)));
    }
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j)
            dp[i][j] = -1;
        }
        return lcsub(n,m,0,s1,s2);
    }
