#define ll long long
 //define ll long long
const int M = 1000000007;

ll powermod(ll a,ll b){
    if(b==1)
    return a;
    if(b==0)
    return 1;
    
    ll tmp = powermod(a,b/2);
    tmp = ((ll)tmp%M * (tmp%M))%M;
    
    if(b%2)
    tmp = ((ll)a*(tmp%M))%M;
    
    return tmp;
}

vector<ll> init(){

    int N = 1005;
    vector<ll>fact(N);
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2;i<N;++i)
    fact[i] = ((ll)i*(fact[i-1]%M))%M;
    return fact;
    
}
    
    
    int nCr(int n, int r){
        // code here
    vector<ll>fact = init();
    if(n<r)
    return 0;

    return (fact[n] * ((powermod(fact[r],M-2)*powermod(fact[n-r],M-2))%M))%M;

    }
