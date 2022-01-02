//dfs call 
void dfs(vector<int>adj[],vector<bool>&vis,int start,int des,int &count)
{
    if(start==des) //if the start node equal destination node,increase the count
    {
        count++;
        return;
    }
    vis[start]=true; //make the starting node as visited
    for(int i:adj[start]) //iterate through the neighbours
    {
        if(!vis[i]) //if not visited,make a recursive dfs call
        dfs(adj,vis,i,des,count);
    }
    vis[start]=false;//once a node finishes it's dfs call, mark it as unvisited while backtracking
}
//Function to count the number of edges
//Algorithm:
/*
1.Make dfs call from the starting node
2.During recursive dfs call,if dest is encountered,count++
3.Once a node finishes it's dfs call,make the node unvisited
4.return count
*/
    int possible_paths(vector<vector<int>>edges, int n, int s, int d){
        // Code here
        int count=0; //to count the number of paths
        vector<int>adj[n]; //to make a adj list out of adj matrix
        for(auto i:edges) //iterate through each row
        {
            adj[i[0]].push_back(i[1]); //assign each row value to its neighbour in adj list
        }
        vector<bool>vis(n,false); //visited array to keep track of visited nodes
        //iterate through the nodes and make a dfs call,if the nodes is not visited
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && i==s)
            {
                dfs(adj,vis,i,d,count);
            }
        }
        return count; //return  the count of the path
    }
};