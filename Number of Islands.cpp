class Solution
{
    public:
    //dfs call
    void dfs(vector<vector<bool>>&vis,int i,int j,int n,int m)
    {
        //base condition
        if(i<0 || i>=n || j<0 ||j>=m || vis[i][j]==true)
        return;
        else
        {
        vis[i][j]=true;//make the current node as visited
        //make recursive dfs call on all 8 directions
        dfs(vis,i+1,j,n,m);
        dfs(vis,i,j+1,n,m);
        dfs(vis,i-1,j,n,m);
        dfs(vis,i,j-1,n,m);
        dfs(vis,i+1,j-1,n,m);
        dfs(vis,i-1,j+1,n,m);
        dfs(vis,i+1,j+1,n,m);
        dfs(vis,i-1,j-1,n,m);
        }
        
    }
    //Function to find the number of islands.
    //Algorithm
    /*
    1. The no. of dfs calls is equivalent to the number of islands
    */
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int ans=0; //to store the count of islands
        //dimension of array
        int n=grid.size();
        int m=grid[0].size();
         vector<vector<bool>> vis( n , vector<bool> (m, true)); //visited array
         //initialization of visited array
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                vis[i][j]=false;
            }
        }
        
        //traversing the 2d matrix and making dfs call
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==false)
                {
                    dfs(vis,i,j,n,m); //dfs call on current node
                    ans++; //increasing the count of islands
                }
            }
        }
        return ans;
    }
};