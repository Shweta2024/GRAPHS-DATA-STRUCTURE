/*
207. Course Schedule

https://leetcode.com/problems/course-schedule/

#Since in this question we are given a particular order in which the tasks has to be done ->Therefore its a question of Topological Sort.
#If there is a situation in which we have to finish task ai before bi & bi before ai .Then it will be impossible to finish both the tasks.In this case it will be forming a cycle & we cannot apply topological sort to a Cyclic graph.Therefore, if we'll get a cycle we will return false else true.
Intuition :-Apply dfs to detect whether there is a cycle or not.If cycle is present return false else return true.

TC=O(V+E)
V->no. of nodes
E->no. of edges
SC=O(n)

*/

class Solution {
public:
    
    //dfs call
    bool dfs(vector<int>adj[],vector<bool>&vist,vector<bool>&anc,int start,int parent)
    {
        vist[start]=true;
        anc[start]=true;
        for(auto i:adj[start])
        {
            if(!vist[i])
            {
                if(dfs(adj,vist,anc,i,start))
                    return true;
            }
            else if (anc[i]==true) return true;
                
        }
        anc[start]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        int n=numCourses;
        vector<int>adj[n];
        vector<bool>vist(n,false);
        vector<bool>anc(n,false);
        for(auto i:prerequisites)
        {
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vist[i])
            {
                if(dfs(adj,vist,anc,i,-1))
                    return false;
            }
        }
    return true;
    }
};