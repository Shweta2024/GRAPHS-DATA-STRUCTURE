class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool dfs(vector<int>adj[],vector<bool>vis,int start,int parent)
    {
        vis[start]=true; // mark the current node as visited
        for(auto i:adj[start]) //iterate through neighbour
        {
            if(!vis[i]) //if current node is not visited,make recursive dfs call
            {
                if(dfs(adj,vis,i,start))
                return true;
            }
            else if(i!=parent) //if visited and not parent,cycle detection
            {
                return true;
            }
        }
        
        return false;
    }
    //Algorithm
    /*
    1.Maintain a parent variable
    2. 2 cases are possible:-i)Node is not visted:Make recursive dfs call ii)Node is visited->if not parent,return false else true
    */
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool>vis(V,false); //To keep track of the visited nodes
	    for(int i=0;i<V;i++) //iterate through all the nodes
	    {
	        if(!vis[i]) //if not visited do a dfs call
	        {
	            if(dfs(adj,vis,i,-1)) //If no cycle return true
	            return true;
	        }
	    }
	    return false;
	}
};