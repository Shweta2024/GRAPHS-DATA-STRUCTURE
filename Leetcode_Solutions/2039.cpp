/*
2039. The Time When the Network Becomes Idle

https://leetcode.com/problems/the-time-when-the-network-becomes-idle/


*/


class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int ans = 0;
        int n = patience.size(); //total no. of nodes

        //adjacency list->{time,adjacent node}
        vector<pair<int,int>>adj[n]; //0-based indexing
        
        //formulate the adjacency list
        for(auto i:edges)
        {
            adj[i[0]].push_back({1,i[1]});
            adj[i[1]].push_back({1,i[0]});
        }

        //creating a min heap
        //pq -> {differnce of time,adjacent node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);//to store the minimum time taken by each node from the source node
        dist[0]=0;//since the time taken by source to send message to itself is ALWAYS 0 
        pq.push({0,0}); //src node dist = 0
        
        //traverse pq untill it gets empty
        while(!pq.empty()) 
        {
            int prev = pq.top().second;//extract prev
            int prev_dist = pq.top().first;//extract  the prev_dist
            pq.pop();//after extracting,pop them from pq
            for(auto i:adj[prev]) //traverse though all the adjacent nodes of prev
            {
                int next = i.second; //extract next
                int next_dist = i.first;//extract next_distance
                if(dist[next] > prev_dist + next_dist)//check if the time taken by next is greater than the new time,then update it
                {
                    dist[next] = prev_dist + next_dist;
                    pq.push({dist[next],next});//push the next node with the updated time value
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