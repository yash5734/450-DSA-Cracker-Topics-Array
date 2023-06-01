class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m= image[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    // int cntOne =0;
    int value = image[sr][sc];
    image[sr][sc] = color;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j] = image[i][j];
        }
    }

    queue<pair<int,int>>q;
    q.push({sr,sc});
    int dr[] = {-1,1,0,0}; 
    int dc[] = {0,0,-1,1}; 
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;

        q.pop();
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr < n&&nr>=0 && nc<m&&nc>=0 && vis[nr][nc] != color &&image[nr][nc] == value){
                vis[nr][nc] = color;
                q.push({nr,nc});
            }
        }
    }



    return vis;

    
        
    }
};
