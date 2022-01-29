
//1971. Find if Path Exists in Graph

class Solution {
public:
    
    //dfs call
    bool dfs(vector<int>adj[],vector<bool>&vist,int start,int destination)
    {
        vist[start]=true;
        if(start==destination) return true;
        for(auto i:adj[start])
        {
            if(!vist[i])
            {
                if(dfs(adj,vist,i,destination))
                    return true;
            }
        }
        return false;
    }
        
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<int>adj[n]; //adjacency list
        vector<bool>vist(n,false); //to keep track of the nodes that has been visited
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(i==source && vist[i]==false)
            {
                if(dfs(adj,vist,i,destination))
                    return true;
            }
        }
        
    return false;
    }
};