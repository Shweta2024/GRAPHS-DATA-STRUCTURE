#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      //if(image[sr][sc]!=newColor)
     dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
        
}
    void dfs(vector<vector<int>>&image,int sr,int sc,int newColor,int oldColor)
{
    if(sr>=image.size() || sr<0 || sc>=image[0].size() || sc<0 || image[sr][sc]!=oldColor || image[sr][sc]==newColor)return;
    
    image[sr][sc]=newColor;
    dfs(image,sr-1,sc,newColor,oldColor);
    dfs(image,sr+1,sc,newColor,oldColor);
    dfs(image,sr,sc-1,newColor,oldColor);
    dfs(image,sr,sc+1,newColor,oldColor);
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends