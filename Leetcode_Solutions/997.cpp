
//997. Find the Town Judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int>v_out(n+1,0);  //to store the no. of outgoing edges
        vector<int>v_in(n+1,0);  //to store the no. of incoming edges
        int ans=-1;
        for(auto i:trust)
        {
            v_out[i[0]]++;
            v_in[i[1]]++;
        }
        
        for(int i=0;i<v_out.size();i++)
        {
            if(v_out[i]==0 && v_in[i]==n-1 )
                ans=i;
                
        }
        return ans;
    }
};