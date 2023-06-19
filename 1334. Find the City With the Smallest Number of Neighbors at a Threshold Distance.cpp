// using floyd algo we can also do by using dijkastra

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));

        for(auto it: edges){
            dis[it[0]][it[1]] = it[2];
            dis[it[1]][it[0]] = it[2];
        }
        
        for (int i = 0; i < n; i++) dis[i][i] = 0;

        for(int via = 0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
                    if (dis[i][via] == INT_MAX || dis[via][j] == INT_MAX)
						continue;
	                dis[i][j] = min(dis[i][j], dis[i][via]+dis[via][j]);
	            }
	        }
	    }

        int cityCount = n;
        int cityNo =-1;
        for(int i=0;i<n;i++){
            int cnt =0;
            for(int j=0;j<n;j++){
                if(dis[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cityCount>=cnt){
                cityCount = cnt;
                cityNo = i;
            }
        }
        return cityNo;

    }
};
