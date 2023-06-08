class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        
        int parent[n+1];
        int dis[n+1];
        
        for(int i=1;i<=n;i++){
            parent[i] = i;
            dis[i] = 1e9;
        }
        dis[1] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            
            for(auto i:adj[node]){
                int v = i.first;
                int w = i.second;
                if(wt+w<dis[v]){
                    dis[v] = wt+w;
                    pq.push({wt+w,v});
                    parent[v] = node;
                }
            }
            
        }
        
        if(dis[n]==1e9) return {-1};
        vector<int>ans;
        int node = n;
        while(node!=parent[node]){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
