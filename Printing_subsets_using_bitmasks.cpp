#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    cin>>a[i];
    
    for(int mask=0;mask<(1<<n);++mask){
        for(int bit = 0;bit<n;++bit)
        {
            if((mask&(1<<bit)) != 0)
            cout<<a[bit]<<"  ";
        }
        cout<<"\n";
    }
    return 0;
}

//only valid for n around less than 64
