# define ll long long int
class Solution {
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        ll ans = 0;
        vector<pair<ll,ll>>adj[n];
        
        for(auto i:roads)
        {
            adj[i[0]].push_back({i[2],i[1]});
            adj[i[1]].push_back({i[2],i[0]});
            
        }
        
        vector<ll>dist(n,INT_MAX);
        vector<ll>way(n,0);
        way[0] =1;
        dist[0] = 0;
        
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
        
        pq.push({0,0});
        
        while(!pq.empty())
        {
            ll prev = pq.top().second;
            ll prev_dist = pq.top().first;
            pq.pop();
            
            if(dist[prev]<prev_dist) continue;
            for(auto i:adj[prev])
            {
                ll next = i.second;
                ll next_dist = i.first;
                if(dist[next]>dist[prev]+next_dist)
                {
                    dist[next] = dist[prev]+next_dist;
                    pq.push({dist[next],next});
                    way[next] = way[prev];
                }
                else if(dist[next]==dist[prev]+next_dist)
                        {
                            way[next]=(way[next] + way[prev])%1000000007;
                        }
            }
        }      
        return way[n-1];
    }
};