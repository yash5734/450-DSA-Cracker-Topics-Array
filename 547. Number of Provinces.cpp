class Solution {
    private:
    void dfs(int node, int* vis,vector<int> adj[]){
        vis[node] = 1;

        for(auto it:adj[node]){
            if(vis[it] ==0){
                dfs(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        int vis[V];
        for(int i=0;i<V;i++){
            vis[i] = 0;
        }
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt =0;
        
        for(int i=0;i<V;i++){
            if(vis[i] == 0){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};
