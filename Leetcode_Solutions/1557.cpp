
/*
1557. Minimum Number of Vertices to Reach All Nodes
Intuition:- Calling the DFS function & marking vist as true if a node gets visited except for the value of node for which we're making DFS call.Finally traversing the vist vector and pushing all the unvisited nodes in the answer.

1. TC=O(n)
1. SC=O(n)
*/

class Solution {
public:
    
    //dfs call
    void dfs(vector<int>adj[],vector<bool>&vist,int start)
    {
        
        for(auto i:adj[start])
        { 
            if(!vist[i])
            {
                vist[i]=true;
                dfs(adj,vist,i);
            }
        }
        
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
    {
        //adj=[[1,2],[],[5],[4],[2]]
        
        vector<int>adj[n];
        vector<bool>vist(n,false);
        vector<int>ans;
        
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(!vist[i])
            {
                dfs(adj,vist,i);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vist[i]==false)
            ans.push_back(i);
        }

    return ans;
    }
};

