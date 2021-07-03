class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    //Intuition:Since we need to find the minimum steps from the source we go ahead with bfs implementation
    //Algorithm
    /*
    1.Since it is one based indexing,modify it by decreasing 1
    2.If the source equals destination coordinates return 0
    3.Apply Bfs
    Increase pointer
    4.look for 8 directions
    5.push it into the queue if not visited
    6.return count
    */
    //T.C: O(V+E)
    //S.C: O(V2)
  int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
  {
      // Code here
      //modification of source and dest coordinates
      int s1=KnightPos[0]-1;
      int s2=KnightPos[1]-1;
      int d1=TargetPos[0]-1;
      int d2=TargetPos[1]-1;
      int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
      int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
      if(s1==d1 && s2==d2) //Base COndition
      return 0;
      int steps=-1; //Since you are already counting one step
      queue<pair<int,int>>q;
      vector<vector<bool>> vis( N , vector<bool> (N, false));
      q.push({s1,s2});
      vis[s1][s2]=true;
      while(!q.empty())
      {
          steps++;
          int count=q.size();
          for(int i=0;i<count;i++)
          {
              pair<int,int>p=q.front();
              int x=p.first;
              int y=p.second;
              q.pop();
              if(x==d1 && y==d2)
              return steps;
              
              for(int i=0;i<8;i++)
              {
                  int xx=x+dx[i];
                  int yy=y+dy[i];
                  
                  if(xx<0 || xx>=N || yy<0 || yy>=N || vis[xx][yy])
                  continue;
                  
                  vis[xx][yy]=true;
                  q.push({xx,yy});
              }
              
          }
      }
      return -1;
  }
};