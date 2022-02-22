/*
886. Possible Bipartition

https://leetcode.com/problems/possible-bipartition/

Intuition :-
1. Maintain a color vector ,initially all elements as -1. //it will keep track of the colors of all adjacent nodes.
2. If a node isn't colored ,then make dfs call & set its color to 1.
3. Now check if its adjacent node isn't colored, then color it as 1-col[start] ,i.e. 1-color of its adjacent node.
4. If its adjacent node is already colored then,check if color of both the nodes are same ,then return false .
5. else return true.

TC=O(N+E)
SC=O(N)

*/

class Solution {
public:
    
    bool dfs(vector<int>adj[],vector<int>&col,int start)
    {
        if(col[start]==-1) col[start]=1;
        for(auto i:adj[start])
        {
            if(col[i]==-1)
            {
                col[i]=1-col[start];
                if(!dfs(adj,col,i))
                    return false;
            }
            else if(col[i]==col[start]) return false;
        }
    return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        n=n+1;//since its 1-based indexing
        vector<int>adj[n];//adjacency list
        
        for(auto i:dislikes)//creating adjacency list
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int>col(n,-1);
        for(int i=1;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(!dfs(adj,col,i))
                    return false;
            }
        }
        
    return true;
    }
};