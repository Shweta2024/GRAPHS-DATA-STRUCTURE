/*
Question: https://www.codechef.com/problems/REVERSE
Approach: 0-1 BFS
What is 0-1 BFS?
0-1 BFS is a approach to find the shortest path in a graph having only 2 weights(0,1).
Similiar questions can be solved using Dijsktra's algorithm as well, but it leads to high T.C.

Intuiton: While performing BFS, at anytime there's only 2 levels inside the queue(x & x+1)
        : If it has lesser or equal weight, push it in front of the queue else push at the back.
        : Need to make use of Double Ended Queue
        : T.C: O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;

int bfs(vector<pair<int,int>>adj[],vector<int>&lev,int n) //0-1BFS
{
    deque<int>q; //to store the node values
    q.push_back(1); //push the starting node
    lev[1]=0; //mark level[1]as level 0
    while(!q.empty()) //keep exploring until queue is empty
    {
        int curr_v = q.front();//first node from queue
        q.pop_front();

    //explore all the adjancent nodes to the current node
        for(auto i:adj[curr_v])
        {
            int child_node = i.first; //extarct the node value
            int wt = i.second; //extract the weight associated
            if(lev[curr_v]+wt<lev[child_node]) //relax the weight of the current node
            {
            lev[child_node]= lev[curr_v]+wt;
            if(wt==1) // if the wt==1 push back
            q.push_back(child_node);
            else //if weight ==0 push in the starting
            q.push_front(child_node);
            }
        }
    }

    return lev[n]==INT_MAX ? -1 : lev[n]; //if there's any disconnected component
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1]; //1-based indexing
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y) continue;
        adj[x].push_back({y,0});
        adj[y].push_back({x,1}); //introduced purposally to transform the question to shortest path
    }

    vector<int>lev(n+1,INT_MAX);
    cout<<bfs(adj,lev,n)<<endl;
    return 0;
}