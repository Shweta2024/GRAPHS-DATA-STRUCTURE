class Solution {
public:
/*
Algorithm:
* Apply dijstra and calculate the time(distance) for all the nodes from source'.
* Return the max time taken, if not return -1
*/
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int total = 0; //to keep trak of the total max time
        vector<pair<int,int>>adj[n+1]; //1-based indexing
        
        //creation of adjaceny list of pair
        for(auto i:times)
        {
            adj[i[0]].push_back({i[2],i[1]});
        }
        
        //creation of min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        //push the start node, dist from src node to start node is 0
        pq.push({0,k});
        
        //declare a distance array of n+1 size
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0; //declare dist[src]=0
        
        //keep traversing the priority_queue
        while(!pq.empty())
        {
            int prev_dist = pq.top().first; //extract the prev_distance
            int prev_node = pq.top().second; //extract the previous node
            pq.pop(); //pop out the current node from the priortity_queue
            for(auto i:adj[prev_node]) //iterate all the adjacent nodes for previous_node
            {
                int next_dist = i.first; //extract next node value
                int  next = i.second; //extract next distance value
                if(dist[next]>dist[prev_node]+next_dist) //relax the distance if required
                {
                   dist[next]=dist[prev_node]+next_dist;  //update the distance vector for next node
                    pq.push({dist[next],next}); //push the next node with the updated distance value
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            total=max(total,dist[i]);
        }
        
        if(total==INT_MAX)return -1;
        return total;
    }
};