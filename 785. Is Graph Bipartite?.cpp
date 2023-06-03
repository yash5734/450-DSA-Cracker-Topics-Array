class Solution {
    private:
    bool check( int start , int vis[], vector<vector<int>>& adj){
        vis[start] = 0;
        queue<int>q;
        q.push(start);
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node])
            if(vis[it] == -1){
                vis[it] = !vis[node];
                q.push(it);

            }
            else{
                if(vis[it] == vis[node]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int vis[n];
        for(int i=0;i<n;i++){
            vis[i] = -1;
        }

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(check(i,vis,graph) == false) return false;
            }
        }
        return true;
    }
};
