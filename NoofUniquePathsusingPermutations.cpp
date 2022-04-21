    int NumberOfPath(int a, int b)
    {
        ll r = b-1;
        ll d = a-1;
        
        ll x = 1;
        
        for(int i=r+d;i>r;i--)
        x *= i;
        
        ll y = 1;
        for(int i=d;i>=2;i--)
        y *= i;
        
        int ans = (x)/y;
        return ans;
    }
