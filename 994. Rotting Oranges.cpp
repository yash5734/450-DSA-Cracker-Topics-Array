class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh =0;
        // {{ i, j},t}
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }

                if(grid[i][j]==1){
                    cntFresh++;
                }

            }
        }

        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};
        int total =0;
        int cnt=0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            total = max(total,tm);
         
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc] == 0 && grid[nr][nc]==1){
                    q.push({{nr,nc},tm+1});
                    vis[nr][nc] = 2;
                    cnt++;
                }
            }

        }
        
        if(cnt!=cntFresh) return -1;

        return total;
    }
};
