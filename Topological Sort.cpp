class Solution
{
	public:
	
	//Make a dfs function
	void dfs(vector<int>adj[],vector<bool>&vis,stack<int>&s,int start)
	{
	    vis[start]=true; //mark the current node as visited
	    for(auto i:adj[start]) //iterate through the adjancent edges
	    {
	        if(!vis[i]) //if not visited,make a recursive dfs call
	        {
	            dfs(adj,vis,s,i);
	        }
	        
	    }
	    s.push(start); //Once a node finishes its dfs call,push into the stack
	}
	//Function to return list containing vertices in Topological order. 
	//Algorithm
	/*
	1.Make dfs call for each node
	2.Once a node finishes its dfs call,push into the stack
	3.Finally,pop the contents of the stack & push into answer vector
	*/
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans; //Array to store the answer
	    stack<int>s; //stack to reverse the order
	    vector<bool>vis(V,false); //Visited array
	    for(int i=0;i<V;i++) //Traverse the nodes
	    {
	        if(!vis[i]) //if not visted,make a dfs call
	        dfs(adj,vis,s,0);
	    }
	   
	   //Push into the resultant array
	   while(!s.empty())
	   {
	       //cout<<s.top()<<endl;
	  ans.push_back(s.top());
	   s.pop();
	   }
	    return ans;
	}
	//T.C:O(V+E)
	//S.C:O(V)
};