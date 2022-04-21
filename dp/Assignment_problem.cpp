#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
int main(){
    vector<vector<int>> matrix;
    int n;
    cin>>n;
    for(auto i=0;i<n;++i){
        int x;
        vector<int> temp;
        for(auto j=0;j<n;++j){
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }

    int p=pow(2,n);
    int dp[p];
    for(auto i=0;i<p;++i){
        dp[i]=INT_MAX;
    }

    dp[0]=0;
    for(auto mask=0;mask<p;++mask){
        int x=__builtin_popcount(mask);
        for(int j=0;j<n;++j){
            if(!(mask & (1<<j))){
                dp[mask | (1<<j)] = min(dp[mask | (1<<j)],dp[mask]+matrix[x][j]);
            }
        }
    }

    for(auto i=0;i<p;++i){
        cout<<dp[i]<<" ";
    }
    cout<<"\nMinimum Cost: "<<dp[p-1];
}

