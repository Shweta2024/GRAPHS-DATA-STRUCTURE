class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int ans = 0;
        int n = patience.size(); //total no. of nodes
        vector<pair<int,int>>adj[n]; //0-based indexing
        
        //formulate the adjacency list
        for(auto i:edges)
        {
            adj[i[0]].push_back({1,i[1]});
            adj[i[1]].push_back({1,i[0]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        pq.push({0,0}); //src node dist = 0
        while(!pq.empty()) 
        {
            int prev = pq.top().second;
            int prev_dist = pq.top().first;
            pq.pop();
            for(auto i:adj[prev])
            {
                int next = i.second;
                int next_dist = i.first;
                if(dist[next] > prev_dist + next_dist)
                {
                    dist[next] = prev_dist + next_dist;
                    pq.push({dist[next],next});
                }
            }
            
        }
        
        for(int i=1;i<n;i++)
        {
            int time = 2*dist[i];
            int curr;
            
            if(patience[i]>=time)
            {
                curr = time;
            }
            
            else
        {
            curr=((time-1)/patience[i]) * patience[i];
            curr+=time;
        }
        ans=max(ans,curr+1);
        }
        
        return ans;
        
        
    }
};