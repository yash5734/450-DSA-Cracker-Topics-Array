class Solution {
private:
    void dfs(vector<vector<char>>& board,int r,int c,vector<vector<int>> &vis,int dr[],int dc[]){
        int n = board.size();
        int m = board[0].size();

        vis[r][c] = 1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc]==0&& board[nr][nc]=='O'){
                dfs(board,nr,nc,vis,dr,dc);
            }
        }

    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int j = 0; j<m;j++){
            if(board[0][j]=='O'){
                dfs(board,0,j,vis,dr,dc);
            }
            if(board[n-1][j]=='O'){
                dfs(board,n-1,j,vis,dr,dc);
            }
        }
        for(int i = 0; i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,vis,dr,dc);
            }
            if(board[i][m-1]=='O'){
                dfs(board,i,m-1,vis,dr,dc);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && vis[i][j]==0){
                    board[i][j] = 'X';
                }
            }
        }
        
        
    }
};
