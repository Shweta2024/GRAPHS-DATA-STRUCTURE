class Solution 
{
    public:
    
    void dfs(vector<int>adj[],vector<bool>&vis,int start)
    {
        vis[start]=true;
        for(auto i:adj[start])
        {
            if(!vis[i])
            dfs(adj,vis,i);
        }
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool>vis(V,false);
	    int ans=-1;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            ans=i;
	            dfs(adj,vis,i);
	        }
	    }
	    
	    for(int i=0;i<V;i++) vis[i]=false;
	    //running the dfs on the last vertex under dfs call
	    dfs(adj,vis,ans);
	    //if all the nodes are visited under dfs call of last vertex,then it is a mother vertex
	    //else return -1
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        return -1;
	    }
	    return ans;
	}

};