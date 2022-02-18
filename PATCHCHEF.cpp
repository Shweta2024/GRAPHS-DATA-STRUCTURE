# include<bits/stdc++.h>
using namespace std;
/*
Approach:
1.You need to find the distance for each node considering every other node as source 
2.then get the maximum value from the above set of distances(this might be onle of the possible longest path)
3.repeat step:2 considering a seperate node as source this time
4.maintain a maximum to store the maximum path length among all the max we get in step:2
5. Compare the value in step:5 with k, if less or equal return 0, else return extra reqd.
*/


void dfs(vector<int>adj[],vector<bool>vis,int n,int c,int start,vector<int>&dist)
{
    vis[start]=true;
    dist[start]=c;
    for(auto i:adj[start])
    {
        if(!vis[i])
            dfs(adj,vis,n,c+1,i,dist);
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>adj[n+1];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c,maxi=INT_MIN;
    vector<int>dist(n+1,0);
    for(int i=1;i<=n;i++)
    {
    vector<bool>vis(n+1,false);
    c=0;
    dfs(adj,vis,n,c,i,dist);
    for(int i:dist)
    {
        maxi=max(maxi,i);
    }
    }
    if(k>=maxi)
    cout<<0<<endl;
    else
    cout<<maxi-k<<endl;
    return 0;
    
}