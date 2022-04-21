int singleElement(int arr[] ,int N) {
    // code here
    int res = 0;
    for(int bit = 0;bit<=31;++bit)
    {
        int cnt_set=0;
        for(int i=0;i<N;++i)
        {
            if((arr[i] & (1ll << bit)) != 0)
            cnt_set++;
        }
        
        if(cnt_set % 3)
        res ^= (1ll<<bit);
    }
    return res;
}