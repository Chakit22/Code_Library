#include <bits/stdc++.h>
using namespace std;

int cnt_Set_bits(int mask){
    int cnt=0;
    for(int i=0;i<31;++i)
    {
        if((mask&(1<<i)) != 0)
        cnt++;
    }
    return cnt;
}

int main()
{
    int n;
    cin>>n;
    int like[n][n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        cin>>like[i][j];
    }
    
    int dp[1<<n]={0};
    dp[0] = 1;
    
    for(int mask = 0;mask<(1<<n);mask++){
        int k = cnt_Set_bits(mask);
        for(int c=0;c<n;++c)
        {
            if(like[k][c] == 1 and (mask&(1<<c)) == 0)
            dp[mask|(1<<c)] += dp[mask];
        }
    }
    
    cout<<dp[(1<<n)-1];
    return 0;
}
