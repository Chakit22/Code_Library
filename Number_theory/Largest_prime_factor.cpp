long long int largestPrimeFactor(int N){
    // code here
    int lar=1;
for(int x=2;x*x<=N;++x)
{
if(N%x==0)
{
lar = x;
while(N%x==0)
N = N/x;
}
}

if(N>1)
lar = N;

return lar;
}
