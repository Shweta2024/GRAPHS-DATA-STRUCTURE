class Solution
{
	public:
	//to find the immediate parent(or set) in which it belongs
	int find_dsu(vector<int>&parent,int i)
	{
	    if(parent[i]==i)
	    return i;
	    return parent[i]=find_dsu(parent,parent[i]); //recursive call
	}
	
	//to perform union of 2 different nodes belonging to 2 different sets using rank
	void union_dsu(int u,int v,vector<int>&parent,vector<int>&rank)
	{
	    int set_u=find_dsu(parent,u); //find the parent of vertex u
	    int set_v=find_dsu(parent,v); //find the parent of vertex v
	    if(rank[set_u]==rank[set_v]) //if the depth of the resp trees is same,do anything
	    {
	        parent[set_u]=set_v; //attaching the set u to v
	        rank[set_v]++; //update the rank of set v
	    }
	    else if(rank[set_u]<rank[set_v]) // if the depth of set u is less than set v,attach set u to v
	    {
	        parent[set_u]=set_v;
	    }
	    else //attach set v to u,incase of rank of set v greater than set u
	    {
	        parent[set_v]=set_u;
	    }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//Algorithm
	/*
	1.Choose th minimum cost edge
	2.If it forms a cycle discard it else accept it
	When we have selected V-1 edges we stop!!
	3.Make use of Disjoint Set to implement
	*/
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>>edgeList; //storing the edges according to weight
        for(int i=0;i<V;i++)
        {
            for(vector<int>j:adj[i])
            {
                edgeList.push_back({j[1],j[0],i});
            }
        }
        //sort the edges according to the weight
        sort(edgeList.begin(),edgeList.end());
        vector<int>parent(V); // vector to store the immediate parent(will be used for path compression)
        vector<int>rank(V,0); //vector to store the rank(depth of the tree)[Used to attach smaller depth tree as child]
        for(int i=0;i<V;i++)
        {
            parent[i]=i; //initially all the nodes are seperately in one set
        }
        int ans=0; //to calculate the final sum of the weights of MST
        for(auto edge:edgeList)
        {
            int w=edge[0]; //weight of the current node
            int u=edge[1]; //vertex u
            int v=edge[2]; //vertex v
            if(find_dsu(parent,u)!=find_dsu(parent,v)) //if the nodes are on the different sets,they need to be unioned
            {
                union_dsu(u,v,parent,rank);
                ans+=w; //adding the weight of the current edge
            }
        }
        
        return ans;
        // T.C: since we are iterating E-1 times,and the complete time complexity of disjoint set takes 
        //O(logn),
        //total T.C: (E-1)log V~ElogV
    }
};