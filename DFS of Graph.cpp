class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};
        vector<int>ans;
        int node =0;
        dfs(node,adj,ans,vis);
        return ans;
    }
    
    void dfs(int node,vector<int> adj[],vector<int> &ans,int* vis){
        ans.push_back(node);
        vis[node] = 1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,adj,ans,vis);
            }
        }
    }
};
