class Solution{
    public:
    
    void dfs(vector<int>g[],vector<bool>&vis,string &res,int start)
    {
        vis[start]=true;
        
        for(int i:g[start])
        {
            if(!vis[i])
            {
                dfs(g,vis,res,i);
            }
        }
        res.push_back('a'+char(start));
    }
    /*
    Algorithm:
    1.Create a directed graph
    2.Traverse the dictionary,compare the adjacent strings.
    3.Find the minimum of the 2 adjacentg string
    4.Keep comparing till the minlength,i.e,the common part
    5.Once the character differs,we get the first point.
    6.Push it into the graph,break
    7.Perform Topological Sort(Make use of vis array,after each dfs push the character into the string)
    8.Note: Instead of passing a stack,pass a strong in topological sort
    9.Reverse the string
    10.Return the string
    11.Important: Make a note of how to push the character into the string & graph
    T.C:O(N2)
    S.C:O(K)
    */
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>g[K];
        for(int i=0;i<N-1;i++)
        {
            int minlength=min(dict[i].length(),dict[i+1].length());
            for(int j=0;j<minlength;j++)
            {
                if(dict[i][j]!=dict[i+1][j])
                {
                    g[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        
        string res="";
        vector<bool>vis(K,false);
        for(int i=0;i<K;i++)
        {
            if(!vis[i])
            {
                dfs(g,vis,res,i);
            }
        }
        
       reverse(res.begin(),res.end());
        //cout<<res<<endl;
        return res;
    }
};