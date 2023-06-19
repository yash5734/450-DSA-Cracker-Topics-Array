class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
	    // to convert the -1 to 1e9
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	               matrix[i][j] = 1e9; 
	            }
	        }
	    }
	    
	    // main algo
	    for(int via = 0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][via]+matrix[via][j]);
	            }
	        }
	    }
	    
	    // to convert 1e9 to -1 as question stated.
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	               matrix[i][j] = -1; 
	            }
	        }
	    }
	}
};
