class Solution {
    private:
    bool checkDfs(int node, int vis[], int pathVis[],vector<int> adj[]){
        vis[node] = 1;
        pathVis[node]= 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(checkDfs(it,vis,pathVis,adj)) return true;
            }
            else if(pathVis[it] == 1) return true;
        }
        
        pathVis[node] =0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V];
        int pathVis[V];
        for(int i=0;i<V;i++){
            vis[i] =0;
            pathVis[i ] =0;
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkDfs(i,vis,pathVis,adj)==true) return true;
            }
        }
        return false;
    }
};
