class Solution
{
    public:
    
    //dfs method
    bool dfs(vector<int>adj[],vector<bool>&vis,vector<bool>&anc,int start,int parent)
    {
        vis[start]=true; //mark the current node as visited
        anc[start]=true; //mark the ancestor as true
        for(auto i:adj[start]) //iterate through the neighbour
        {
            if(!vis[i]) //if not visited,make recursive dfs call
            {
                if(dfs(adj,vis,anc,i,start)) //if  cycle detected,return true
                return true;
            }
            else if(anc[i]==true) //if the edge is to anyone of the ancestor,return true
            {
                return true;
            }
        }
        
        anc[start]=false; //while backtracking,make ancestor false
        
        return false;
    }
	//Function to detect cycle in a directed graph.
	//Algorithm
	/*
	1.Maintain ancestor instead of parent cuz every visited node is not parent
	2.Make recursive dfs call
	*/
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<bool>vis(V,false);
	   	vector<bool>anc(V,false);
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!vis[i])
	   	    {
	   	    if(dfs(adj,vis,anc,i,-1))
	   	    return true;
	   	    }
	   	}
	   	
	   	return false;
	}
};