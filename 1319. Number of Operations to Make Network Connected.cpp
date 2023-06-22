
class disJointSet{
    public:
    vector<int>rank,parent,size;
    disJointSet(int n){
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


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraEdges =0;
        disJointSet ds(n);

        // this for loop is used to count the extra edges
        int extra =0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUlParent(u)==ds.findUlParent(v)){
                extra++;
            }
            else{
               ds.unionByRank(u,v); 
            }
        }

        // this loop is used to count the number of components;
        int compo =0;
        for(int i=0;i<n;i++){
            if(ds.findUlParent(i)==i){
                compo++;
            }
        } 

        int ans = compo-1; // minimum number of edges require to get connectes the compo;

        if(ans<=extra) return ans;
        return -1;

    }
};
