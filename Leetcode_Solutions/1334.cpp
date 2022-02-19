/*
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

We are supposed to find the city with minimun neighbors such that the neighbors can be reached with a distance less than or equal to the threshold. If there exists multiple cities then we have to return the city with greater number.

intuition :- 
1. Create the adjacency list.
2. Use a for loop , because we have to find minimum distances of every nodes from every other nodes.So taking a node as source,one at a time.
3.  Use Dijsktra Algorithm, to find the minimum distances of every nodes from the source node.  
4.  Use an unordered_map to store the number of the cities that are reachable with a distance less than or equal to threshold from the i-th city.  
5.  At last, find the key with least value and return it. If multiple keys are possible answer then return the max of them.

TC=O(N+E)
N->no. of nodes & E->no. of edges
SC=O(N)

*/



class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        //creating adjacency list
        vector<pair<int,int>>adj[n];//array->vector->vector->int
        for(auto i:edges)
        {
            adj[i[0]].push_back({i[2],i[1]});
            adj[i[1]].push_back({i[2],i[0]});//from node->weight,to node
        }
        
        unordered_map<int,int>cities;    
        for(int i=0;i<n;i++)
        {
            vector<int>dist(n,INT_MAX);//to keep track of the minimum distances of all cities for the source city; (taking each city as sources ,one city at a time)
        
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            
            dist[i]=0;
            pq.push({0,i});//distance,node
            
            while(pq.size()>0)
            {
                int w1=pq.top().first;//weight
                int n1=pq.top().second;//node
                pq.pop();
                for(auto j:adj[n1])
                {
                    int w2=j.first;
                    int n2=j.second;
                    if(dist[n1]+w2<dist[n2])
                    {
                        dist[n2]=dist[n1]+w2;
                        pq.push({dist[n2],n2});
                    }
                }
            }
            for(auto j:dist)
            {
                if(j<=distanceThreshold && j!=0)
                    cities[i]++;//incrementing the value corresponding to the i-th the key whenever a distance(except 0) less than threshold is encountered. 
            }
        }
        
        //finding the city with minimun neighbours 
        int mini=cities[0];
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(cities[i]<=mini)
            {
                mini=cities[i];
                ans=i;   
            }
        }
        
    return ans;
    }
};