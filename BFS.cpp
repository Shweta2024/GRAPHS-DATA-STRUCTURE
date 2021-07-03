class Solution {
public:
//bfs function
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int>v; //final bfs to store the answer
	    queue<int>q; //queue
	    bool visited[V+1]; //visited array 
	    //initialization of visited array
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    //push the first element
	    q.push(0);
	    //marked it as visited
	    visited[0]=true;
	    //iterate over the queue
	    while(q.size()>0)
	    {
	        int temp=q.front(); //extract the first element
	        q.pop(); //pop the curr element from the queue
	        v.push_back(temp); //push the curr element to answer
	        for(int i=0;i<adj[temp].size();i++) //traverse through the connected nodes
	        {
	            if(!visited[adj[temp][i]]) //if the node is not visited,push into the queue
	            {
	                q.push(adj[temp][i]);
	                visited[adj[temp][i]]=true; //mark the node as visited
	            }
	        }
	    }
	    return v;//return the answer containing the traversal
	}
};