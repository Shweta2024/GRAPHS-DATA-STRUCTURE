/*

802	Find Eventual Safe States

https://leetcode.com/problems/find-eventual-safe-states/

Intuition :- Question is asking us to find nodes that are not in a cycle
Perform a simple DFS and keep track of visited nodes
We know "leaf" nodes are safe, and any nodes with only safe "children" are also safe
If we find a node already visited, we know it is not safe
Keep track of these two things (safe and cycle nodes) and return the safe ones.

TC=O(N+E)
SC=O(N)

*/

class Solution {
public:
    unordered_set<int> cycle_nodes;
    unordered_set<int> safe_nodes;
    
    bool dfs (const vector<vector<int>>& g, int i, unordered_set<int> visited_nodes) 
    {    
        if (safe_nodes.find (i)  != safe_nodes.end ())  return true;  // we know safe already
        if (cycle_nodes.find (i) != cycle_nodes.end ()) return false; // we know in cycle already
        
        if (visited_nodes.find (i) != visited_nodes.end ()) 
        {         // we have determined node is in cycle
            cycle_nodes.insert (i);
        return false;
        }
        visited_nodes.insert (i); // keep track of nodes we've visited already

        for (int node : g[i]) 
        {
            if (!dfs (g, node, visited_nodes)) 
            {
                cycle_nodes.insert (i); // if child is in cycle, parent must be too
            return false;
            }
        }

        safe_nodes.insert (i); // we know node is safe now
        
    return true;
}

    
vector<int>eventualSafeNodes(vector<vector<int>>& graph) 
{
    vector<int> ans;
    unordered_set<int>visited_nodes;
        
    for (int i = 0; i < graph.size (); i++) 
    {
        if (dfs (graph, i, visited_nodes)) ans.push_back (i);
    }
        
    return ans;
    }
};