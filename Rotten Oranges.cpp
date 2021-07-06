class Solution {
public:
//Algorithm
/*
Intuition:Since we need to explore all neighbours in a circular manner we make use of bfs
Algorithm: 
1.Push the intial coordinates of the rotten oranges in the queue
2.Keep a track of the no. of fresh oranges,once it becomes rotten decrease the count
3.At the end check the no. of fresh oranges,if 0 return timer,else -1
T.C:O(N*M)
*/
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten; //qeueue
        int r = grid.size(), c = grid[0].size(), fresh = 0, t = 0;
        //iterate through the array push all the coordinates of rotten oranges into queue,
        //also keep track of fresh oranges
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(grid[i][j] == 2) rotten.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        //Apply bfs traversal
        while(!rotten.empty()){
            int num = rotten.size();
            for(int i = 0; i < num; ++i){
                int x = rotten.front().first, y = rotten.front().second; //take the coordinates
                rotten.pop();
                //explore all 4 directions
                if(x > 0 && grid[x-1][y] == 1){ grid[x-1][y] = 2; fresh--; rotten.push({x-1, y});};
                if(y > 0 && grid[x][y-1] == 1){ grid[x][y-1] = 2; fresh--; rotten.push({x, y-1});};
                if(x < r-1 && grid[x+1][y] == 1){ grid[x+1][y] = 2; fresh--; rotten.push({x+1, y});};
                if(y < c-1 && grid[x][y+1] == 1){ grid[x][y+1] = 2; fresh--; rotten.push({x, y+1});};
            }
            //if still rotten oranges are there in teh queue after first iteration,increase timer
            if(!rotten.empty()) t++;
        }
        return (fresh == 0) ? t : -1; //check for fresh oranges
    }
};