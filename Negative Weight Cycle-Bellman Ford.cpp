/*
If there is a negative cycle, we can't apply Bellman-Ford
Bellman Ford algorithm helps detecting negative cycle
(Once you hsve relaxed the graph N-1 times, if you try to relax once more and there is decrease in dist there is a negative cycle)
Bellman works in directed graph only
Incase of undirected graph, it needs to be converted to directed graph
*/
#include<bits/stdc++.h>
class Solution
{
	public:
	
    
    int mini(vector<bool>proc,vector<int>dist,int V) // Function to select the minimum dist node
    {
        int m=INT_MAX; // to keep track of the distance
        int m_index; //to keep track of the index of the minimum distance node
        for(int i=0;i<V;i++) //Traverse through all the nodes
        {
            if(!proc[i] && dist[i]<m) //Check if it's not processsed and dist is minimum
            {
                m=dist[i];
                m_index=i;
            }
        }
        return m_index; //return the index(cuz index is stored as the node value)
    }
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>>adj[], int S)
    {
        // Code here
        //Make use of 2 arrays, one for keeping track of the processed nodes and the other to keep track of the shortest distances from the source
        /*
        1. Choose the smallest distance node, mark it as processed
        2. Relax(Update) it's neighbour(if curr edge wt.+dis[of previous]<dist[current])
        3. dis[u] + wt < dist[v]
        4.T.C.: O(N-1)*O(E)
        5. S.C.: O(N)
        */
        // Make a note of the representation of the weighted undirected graph using stl
        vector<bool>proc(V,false); // Array to keep track of the processed nodes
        vector<int>dis(V,INT_MAX); //Array to keep track of the min dist from source to all the nodes
        dis[S]=0; //Intial distance from source to source is 0
       
        for(int i=0;i<V-1;i++) // Iterate through the first V-1 nodes(leaving the last node, since it has nothing to relax)
        {
            int u=mini(proc,dis,V); // Pick the minimum distance node from the set of unprocessed nodes
             proc[u]=true; // Mark the current node as processed
        for(auto v:adj[u]) // Traverse through all of it's neighbour
            {
                    if(v[1]+dis[u]<dis[v[0]]) //Relax(Update the minimum dist)
                    {
                        dis[v[0]]=v[1]+dis[u];
                    }
                    
            }
        }
        
        return dis; //Return thr final list of updated minimum distance
    }
};