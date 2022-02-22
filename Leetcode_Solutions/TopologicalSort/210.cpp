/*
Course Schedule II

https://leetcode.com/problems/course-schedule-ii/

Intuition :-
1. Create the adjacency list. 
2. Apply cycle detection in a directed graph.
3. If cycle exists =>its impossible to complete all courses ,so return an empty array.
4. If cycle doesn't exists then=>Apply TOPOLOGY SORT
5. And finally return the ans.

TC=O(V+E)
SC=O(N)

*/

class Solution {
public:
    bool cycle_dfs(vector<int>adj[],vector<bool>&vist,vector<bool>&anc,int start,int parent)
    {
        vist[start]=true;
        anc[start]=true;
        for(auto i:adj[start])
        {
            if(!vist[i])
            {
                if(cycle_dfs(adj,vist,anc,i,start))
                    return true;
            }
            else if (anc[i]==true)
                return true;
        }
        anc[start]=false;
        return false;
    }
    bool is_cycle(vector<int>adj[],int n)
    {
        vector<bool>vist(n,false);
        vector<bool>anc(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!vist[i])
            {
                if(cycle_dfs(adj,vist,anc,i,-1))
                return true;
            }
        }
    return false;
    }
        

    
    void topo_dfs(vector<int>adj[],vector<bool>&vist,stack<int>&stk,int start)
    {
        vist[start]=true;
        for(auto i:adj[start])
        {
            if(!vist[i])
                topo_dfs(adj,vist,stk,i);
        }
        stk.push(start);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n=numCourses;//no. of courses
        vector<int>ans;//to store the ans
        
        
        
        vector<int>adj[n];//adjacency list
        for(auto i:prerequisites)//creating adjacency list
            adj[i[1]].push_back(i[0]);


        //if this holds =>cycle exists =>its  impossible to finish all courses 
        if(is_cycle(adj,n))
            return ans;
        
        else
        {
            vector<bool>vist(n,false);
            stack<int>stk;
            for(int i=0;i<n;i++)
            {
                if(!vist[i])
                    topo_dfs(adj,vist,stk,i);
            }
            
            while(stk.size()>0)
            {
                int temp=stk.top();
                stk.pop();
                ans.push_back(temp);
            }
        }
    return ans;
    }
};