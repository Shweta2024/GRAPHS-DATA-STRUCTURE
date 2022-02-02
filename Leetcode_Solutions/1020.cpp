/*
1020. Number of Enclaves

https://leetcode.com/problems/number-of-enclaves/


#In this question, we were asked to find the number of land cells(1) for which we cannot walk off the boundary of the grid. This means we don't need to consider the 
boundary 1's because they will results in walking off from the boundary.


Intuition :- Making all the boundary 1's as 0. Followed by traversing the matrix , the total number of 1 is equal to the total number of land cells for which we cannot
walk off the boundary.

1. TC=O(n^2)
2. SC=O(1)

*/
class Solution {
public:
    
    //dfs call
    void dfs(vector<vector<int>>&grid,int i,int j,int r, int c)
    {
        if(i<0||j<0||i>=r||j>=c||grid[i][j]==0) return;
        
        grid[i][j]=0;
        dfs(grid,i+1,j,r,c);
        dfs(grid,i-1,j,r,c);
        dfs(grid,i,j+1,r,c);
        dfs(grid,i,j-1,r,c);
    }

    
    int numEnclaves(vector<vector<int>>& grid)
    {
        int ans=0;
        int r=grid.size();
        int c=grid[0].size();
        
        //making all boundary 1's as 0
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1 && (i==0||i==r-1||j==0||j==c-1))
                {
                    dfs(grid,i,j,r,c);
                }
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                    ans++;
            }
        }
    return ans;
    }
};


