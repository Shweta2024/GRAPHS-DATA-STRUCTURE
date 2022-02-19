/*
Implementing Dijkstra Algorithm

https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

*/


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<bool>vist(V,false);//to keep track of the nodes that has been visited
        vector<int>dist(V,INT_MAX);//to store distance of every vertex from the source
        //Since we have to find the min distance,therefore initially taking all distance
        //as INT_MAX
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //pair<int,int> ->weight,node
        //its a min heap
        
        dist[S]=0;//the distance of source from itself is always 0
        
        pq.push({0,S});//pushing the weight & the node
        
        while(pq.size()>0)
        {
            int w1=pq.top().first;
            int n1=pq.top().second;
            pq.pop();
            
            for(auto i:adj[n1])
            {
                int w2=i[1];
                int n2=i[0];
                if(dist[n1]+w2<dist[n2])
                {
                    dist[n2]=dist[n1]+w2;
                    pq.push({dist[n2],n2});
                }
                
            }
        }
    return dist;
        
    }
};