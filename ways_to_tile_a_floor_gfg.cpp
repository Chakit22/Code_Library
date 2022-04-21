long long numberOfWays(long long N) {
    //code here
    int M = 1000000007;
    if(N==1 or N==2)
    return N;
    
    int a = 1;
    int b = 2;
    int c;
    
    for(int i=3;i<=N;++i){
        c = (a%M + b%M)%M;
        a = b;
        b = c;
    }
    return c;
}