# define INF INT_MAX
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    //Algorithm
	    /*
	    1.Consider one vertex at a time as an itermediate and update the distance vertex
	    Next,time consider additional one vertex as a intermediate node and update the distance
	    matrix
	    Keep doing this until you have taken into consideration all the nodes
	    The last updated distance matrix will be the answer.
	    */
	    
	    
	    int v=matrix.size(); //finding the size of the matrix
	    
	    // initializing the -1 to INT_MAX
	    for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				if(matrix[i][j] == -1)
					matrix[i][j] = INF;
			}
		}
		
		//choosing k vertices as an intermediate
	    for(int k=0;k<v;k++)
	    {
	        //start traversing the entire matrix
	        for(int i=0;i<v;i++)
	        {
	            for(int j=0;j<v;j++)
	            {
	            //weight relaxtion
	            if(matrix[i][k]!=INF && matrix[k][j]!=INF)
	            {
	                if(matrix[i][k]+matrix[k][j]<matrix[i][j])
	                {
	                    matrix[i][j]=matrix[i][k]+matrix[k][j];
	                }
	            }
	       }
	        }
	    }
	    
	    //reinitializing the INT_MAX to -1
	    for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				if(matrix[i][j]>=INF)
					matrix[i][j] =-1;
			}
		}
	    
	}
};