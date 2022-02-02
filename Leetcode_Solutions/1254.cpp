/*

1254. Number of Closed Islands

https://leetcode.com/problems/number-of-closed-islands/


#In this question we were asked to find the lands(0's) that were 4-Directionally surrounded by water (1). So, it is obvious that we won't consider the boundary 0's 
because it can never be 4-directionally surrounded by water(at max ,the boundary 0's can be 3-directionally surrounded with water).

**Intuition :** Make all the boundary 0's as 1. Followed by making DFS call. The total number of DFS calls gives the total number of closed island.

1. TC=O(n^2)
2. SC=O(1)
*/

class Solution {
public:
    
    //dfs call
    void dfs(vector<vector<int>>&grid,int i,int j,int r,int c)
    {
        if(i<0||j<0||i>=r||j>=c||grid[i][j]==1) return;
        
        grid[i][j]=1;
        dfs(grid,i+1,j,r,c);
        dfs(grid,i-1,j,r,c);
        dfs(grid,i,j+1,r,c);
        dfs(grid,i,j-1,r,c);
        
    }
    
    int closedIsland(vector<vector<int>>& grid)
    {
        //closed island->4-directionally surrounded by 1
        int ans=0;
        int r=grid.size();     //no. of rows
        int c=grid[0].size();  //no. of columns
        
        
        //making all boundary 0's as 1.
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==0 && (i==0||j==0||i==r-1||j==c-1))
                {
                    dfs(grid,i,j,r,c);
                }
            } 
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(grid,i,j,r,c);
                    ans++;
                }
            }
        }
    return ans;
        
    }
};

/*
[[0,0,1,1,0,1,0,0,1,0],[1,1,0,1,1,0,1,1,1,0],[1,0,1,1,1,0,0,1,1,0],[0,1,1,0,0,0,0,1,0,1],[0,0,0,0,0,0,1,1,1,0],[0,1,0,1,0,1,0,1,1,1],[1,0,1,0,1,1,0,0,0,1],[1,1,1,1,1,1,0,0,0,0],[1,1,1,0,0,1,0,1,0,1],[1,1,1,0,1,1,0,1,1,0]]
*/
