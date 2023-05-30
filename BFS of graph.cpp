class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        int vis[V] ={0};
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            
            for(auto it:adj[temp]){
                if(vis[it] == 0){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
