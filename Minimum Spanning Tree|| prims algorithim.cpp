class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        int sum = 0;
        pq.push({0,0}); // if we want mst then we can add parent also in pq
                        // and store the node and parent in some ds and our mst is find.
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(vis[node]==1)continue;
            vis[node] =1;
            sum += wt;
            
            for(auto it:adj[node]){
                int adjNode = it[0];
                int adjWt = it[1];
                if(!vis[adjNode]){
                    pq.push({adjWt,adjNode});
                }
            }
            
        }
        return sum;
    }
};
