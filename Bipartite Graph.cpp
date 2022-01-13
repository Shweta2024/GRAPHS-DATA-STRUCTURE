#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    bool dfs(vector<int>adj[],vector<int>&col,int start,int cr)
    {
        bool flag=true; //mark the bipartition
        col[start]=cr; //color the current node
        for(int i:adj[start]) //iterate through all the nodes
        {
            if(col[i]==-1) //if the current child is not colored,make a recursive dfs call
            {
                flag=dfs(adj,col,i,1-cr); //track of the bipartition
                if(!flag)//if any of the non-colored nodes violate the rule,return false
                return false;
            }
            else
            {
                if(col[i]==col[start]) //if the color of parent and  current node is same,return false
                {
                    return false;
                }
            }
        }
        return true;// If all nodes satisfy the condition and is colored return true
        
    }
    //Algorithm
    /*
    1.Apply DFS
    2.Maintain a color array instead of vis array
    3.If the node is unvisited,make a recursive dfs call and get the answer for the rest of the unvisited nodes
    4.If visited,2 cases follow-i)Color of parent and current node is same,return false ii)return trueas colors are differnt
    */
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    bool flag=true; // to keep track of each set as bipartite
	    vector<int>col(V,-1); //keep track of colors;all the nodes are initially colored as -1
	    for(int i=0;i<V;i++)//iterate through all the nodes
	    {
	        if(col[i]==-1) //if it hasnt been colored,call dfs
	        {
	            flag=dfs(adj,col,i,0); //keep a check on the bipartite nature
	            if(!flag) //if any one node doesnt follow bipartatie nature,return false
	            return false;
	        }
	    }
	    
	    return true;//if every node is colored and non violated the condition of bipartition,return true
	}
	//T.C:O(V+E)
	//S.C:O(V+E)

};