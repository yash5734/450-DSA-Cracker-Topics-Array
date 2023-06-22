class DisJointSet{
    
    vector<int>rank,parent,size;
    public:
    DisJointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int findUlParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUlParent(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int ulp_u = findUlParent(u); 
        int ulp_v = findUlParent(v);
        
        if(ulp_v==ulp_u) return; // exit bcz both the node have same component;
        
        if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{  // rank is same now increase the rank by one;
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
};
class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // store {wt,{u,v}} in vector to sort;
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            int wt = it[1];
            int adjNode = it[0];
            int node = i;
            
            edges.push_back({wt,{node,adjNode}});
        }
        }
        
        sort(edges.begin(),edges.end());
        
        DisJointSet ds(V);
        
        int mstWt = 0;
        
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUlParent(u) != ds.findUlParent(v)){
                mstWt+=wt;
                ds.unionByRank(u,v);
            }
        }
        return mstWt;
    }
};
