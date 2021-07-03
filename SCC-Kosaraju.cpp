class Solution
{
	public:
	//second dfs traversal on reveresed graph
	void dfs2(vector<int>adj_rev[],int V,int start,vector<bool>&vis)
	{
	    vis[start]=true;
	    for(auto i:adj_rev[start])
	    {
	        if(!vis[i])
	        {
	            dfs2(adj_rev,V,i,vis);
	        }
	    }
	}
	
	//first dfs traversal on original graph to populate the graph
	void dfs1(vector<int>adj[],int V,int start,stack<int>&s,vector<bool>&vis)
	{
	    vis[start]=true;
	    for(auto i:adj[start])
	    {
	        if(!vis[i])
	        {
	            dfs1(adj,V,i,s,vis);
	        }
	    }
	    s.push(start);
	}
	//Function to find number of strongly connected components in the graph.
	//Algorithm
	/*
	The algorithm used is divided into 2 parts.
1) We perform dfs i.e depth first search on graph, when it is done, we put that element in stack.
2) We reverse the graph, keep popping elements from the graph, when we get non-visited node, we perform dfs, and it gives 1 strongly connected component.
3)Number of dfs calls are the number of strongly connected components.
*/
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        int ans=0; // to store the count of SCC
        vector<bool>vis(V,false); //keep track of the visited nodes
        stack<int>s; // stack to store the nodes
        //first dfs call
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
            dfs1(adj,V,i,s,vis);
            }
        }
        //reversing of graph
        vector<int>adj_rev[V];
        for(int i=0;i<V;i++)
        {
        for(int j:adj[i])
        {
            adj_rev[j].push_back(i);
        }
        }
        //re-initializing the vis array to false
        for(int i=0;i<V;i++)
        {
            vis[i]=false;
        }
        //running dfs once again on the elements in the stack once again
        while(!s.empty())
        {
            int a=s.top();
            s.pop();
            if(!vis[a])
            {
            dfs2(adj_rev,V,a,vis);
            //the number of dfs call required finds the SCC
            ans++;
            }
        }
        return ans;
        //T.C: O(V+E)
    }
};