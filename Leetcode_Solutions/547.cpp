/*
547. Number of Provinces

https://leetcode.com/problems/number-of-provinces/


Intuition :-Simply apply DFS . The number of times the DFS function will call =The number of Provinces.

TC=O(n^2)
SC=O(n)
*/
class Solution {
public:
    
    //dfs call
    void dfs(vector<int>adj[],vector<bool>&vist,int start)
    {
        vist[start]=true;
        for(auto i:adj[start])
        {
            if(!vist[i])
                dfs(adj,vist,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n=isConnected.size(); //3
        vector<bool>vist(n+1,false); //to keep track of the nodes that has been visited
        vector<int>adj[n+1]; //adjacency list
        
        //creating adjacency list
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        //adj=[[],[1,2],[1,2],[3]]
        
        int ans=0;
        for(int i=1;i<n+1;i++)// i->1-4 ; 1-2-3
        {
            if(!vist[i])
            {
                dfs(adj,vist,i);
                ans++; //gives the no. of provinces
            }
        }
    return ans;
    }
};
