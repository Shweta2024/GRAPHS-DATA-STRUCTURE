//1791. Find Center of Star Graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        int ans=0;
        int n=edges.size();
        vector<int>v(n+2,0);
        for(auto i:edges)
        {
            v[i[0]]++;
            v[i[1]]++;
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==n)
                ans=i;
        }
        return ans;
    }
};


