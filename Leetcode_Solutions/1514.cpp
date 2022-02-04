
/*
Algorithm:
* Use Dijsktra's but with Max Heap since you need to keep track of max prob.
*/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double ans =0;
        vector<pair<int,double>>adj[n];
        int j =0;
        for(auto i:edges)
        {
            adj[i[0]].push_back({i[1],succProb[j]});
            adj[i[1]].push_back({i[0],succProb[j]});
            j++;
        }
        
        priority_queue<pair<int, double>,vector <pair<int, double>>> pq;
        vector<double>dist(n,0.0);
        pq.push({start,1.0});
        dist[start]=1;
        while(!pq.empty())
        {
            double prev_prob = pq.top().second;
            int prev = pq.top().first;
            pq.pop();
            for(auto i:adj[prev])
            {
                int next = i.first;
                double next_prob = i.second;
                if(dist[next]<dist[prev] * next_prob)
                {
                    dist[next]=dist[prev]*next_prob;
                    pq.push({next,dist[next]});
                }
            }
        }
        
        for(auto i:dist)
        {
            cout<<i<<endl;
        }
            return dist[end];
        
    }
};