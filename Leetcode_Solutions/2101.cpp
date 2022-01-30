/*
# Detonate the Bomb
# https://leetcode.com/problems/detonate-the-bomb/

Intuition: How can this question be solved by graph? ->Each bomb can be treated as a bomb and then the start bomb points to others(directed graph).
* Use x2+y2<=r2 Formula from Circle to check for the bombs in the vicinity.
* Algorithm:
* Perform dfs starting from each bomb and check how many bombs it can detonate.
* Maintain a max, update it after each dfs call.
* return max.
* Note: Please take care of overflow(use long long) and pass by reference for (TLE)
* T.C.: O(n*n)
* S.C:.O(n*n)
*/

#define ll long long int
class Solution {
public:
    
    void dfs(vector<vector<int>>&graph, vector<bool>&vis, int &cnt,int start)
    {
        vis[start]=true;
        cnt++;
        for(auto i:graph[start])
        {
            if(!vis[i])
            {
                dfs(graph,vis,cnt,i);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        int n=bombs.size();
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++)
        {
            ll x1,y1,r1;
            x1=bombs[i][0]; //6
            y1=bombs[i][1]; //1
            r1=bombs[i][2]; //4
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                     ll x2,y2,r2;
                     x2=abs(x1-bombs[j][0]); //4
                     y2=abs(y1-bombs[j][1]); //0
                    if(x2*x2+y2*y2<=r1*r1)
                    {
                        graph[i].push_back(j);
                    }
                }
            }
        }
        
        int results = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            vector<bool>vis(n,false);
            dfs(graph,vis,cnt,i);
            results = max(results,cnt);
        }
        return results;
    }
};