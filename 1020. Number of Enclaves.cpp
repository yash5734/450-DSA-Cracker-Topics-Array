class Solution {
private:
    void dfs(vector<vector<int>>& grid,int r,int c,vector<vector<int>> &vis,int dr[],int dc[]){
        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc]==0&& grid[nr][nc]==1){
                dfs(grid,nr,nc,vis,dr,dc);
            }
        }

    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int j = 0; j<m;j++){
            if(grid[0][j]==1){
                dfs(grid,0,j,vis,dr,dc);
            }
            if(grid[n-1][j]==1){
                dfs(grid,n-1,j,vis,dr,dc);
            }
        }
        for(int i = 0; i<n;i++){
            if(grid[i][0]==1){
                dfs(grid,i,0,vis,dr,dc);
            }
            if(grid[i][m-1]==1){
                dfs(grid,i,m-1,vis,dr,dc);
            }
        }
        int cntGrid= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    cntGrid++;
                }
            }
        }
        int cntvis= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 1){
                    cntvis++;
                }
            }
        }
        return cntGrid-cntvis;
        
    }
};
