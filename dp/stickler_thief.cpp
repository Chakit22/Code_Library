 int FindMaxSum(int a[], int n)
    {
        // Your code here
        vector<pair<char,pair<int,int>>>dp(n+1);
        for(int i=0;i<=n;++i)
        {
            dp[i].first = 'n';
            dp[i].second.first = -1;
            dp[i].second.second = 0;
        }
        
        dp[1].second.second = a[0];
        dp[1].first = 'i';
        
        for(int i=2;i<=n;++i)
        {
            if(a[i-1] + dp[i-2].second.second <= dp[i-1].second.second){
                dp[i].first = 'n';
                dp[i].second.first = i-1;
                dp[i].second.second = dp[i-1].second.second;
            }else{
                dp[i].first = 'i';
                dp[i].second.first = i-2;
                dp[i].second.second = a[i-1] + dp[i-2].second.second;
            }
        }
        return dp[n].second.second;
}
