class Solution 
{
    public:
    //dfs function
    void dfs(vector<int>adj[],vector<bool>&vis,vector<int>&res,int start)
    {
        vis[start]=true; //mark the current node as visited
        res.push_back(start); //push the curretn node in the resutant array
        for(int i:adj[start]) //iterate through all it's neighbour
        {
            if(!vis[i]) //if not visited,make a recursive dfs call on it's neighbour
            {
                dfs(adj,vis,res,i);
            }
        }
        
    }
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<bool>vis(V,false); //to keep track of the visted nodes
	    vector<int>res; //to store the resultant dfs traversal
	    for(int i=0;i<V;i++) //iterate thourgh all the vertices
	    {
	        if(!vis[i]) //if not visited,make recursive dfs call
	        {
	            dfs(adj,vis,res,i);
	        }
	    }
	    
	    return res;//return ans
	}
	//T.C:O(V+E)
	//S.C:O(V)
};