#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&ans,vector<int>&vis,vector<int> adj[]){
    
    for(auto i: adj[node]){
        if(!vis[i]){
        vis[i] = 1;
        ans.push_back(i);
        dfs(i,ans,vis,adj);
        }
    }
}


int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    
    vector<int>adj[nodes+1];
    
    for(int i=0;i<edges;++i)
    {
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>ans;
    vector<int>vis(nodes + 1,0);

    for(int i=1;i<=nodes;++i){
        if(!vis[i]){
            vis[i] = 1;
            ans.push_back(i);
            dfs(i,ans,vis,adj);
        }
    }
    
    for(auto i :ans)
    cout<<i<<"  ";
    
    cout<<"\n";
    return 0;
}
