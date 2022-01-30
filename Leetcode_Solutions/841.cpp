
/*
841. Keys and Rooms

Why are we using BFS?
-
Intuition :- Do BFS traversal & keep track of all the visited nodes.Traverse the vist vector , if any of its value is false then return false else return true.
vist->false->it wasn't visited
vist->true->it was visited

1. TC=O(n)
1. SC=O(n)
*/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n=rooms.size();
        vector<bool>vist(n,false);
        queue<int>q;
        
        q.push(0);
        vist[0]=true;
        
        while(q.size()>0)
        {
            int temp=q.front();
            q.pop();
            for(int i=0;i<rooms[temp].size();i++)
            {
                if(!vist[rooms[temp][i]])
                {
                    vist[rooms[temp][i]]=true;
                    q.push(rooms[temp][i]);
                }
            }
            
        }
        for(int i=0;i<n;i++)
        {
            if(vist[i]==false)
                return false;
        }
    return true;
    }
};