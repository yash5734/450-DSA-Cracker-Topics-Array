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
    
    void unionBySize(int u,int v){
        int ulp_u = findUlParent(u); 
        int ulp_v = findUlParent(v);
        
        if(ulp_u == ulp_v) return; 
        
        if(size[ulp_v]<size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        // maxrow and max col are the maximum no. of row and col
        int maxRow =0; 
        int maxCol =0;
        for(auto it: stones){
            maxRow = max(maxRow,it[0]); // this is for row
            maxCol = max(maxCol,it[1]); // this is for column
        }


        disJointSet ds(maxRow+maxCol+1); // costruct the dj ds 
        unordered_map<int,int>mp;
        for(auto it: stones){
            int nodeRow = it[0];// convert the col number ie. if there are 4 row and 3col and ow is {0,1,2,3,} and 
            int nodeCol = it[1]+maxRow+1; //col {5,6,7,8} 

            ds.unionByRank(nodeRow,nodeCol);
            mp[nodeRow] =1; // it store the row and col
            mp[nodeCol] =1;
        }

        int cnt=0; //total no of compo and the node which we can not count ie the node which it self    
        for(auto it:mp){ // a ultimate parent node;
            if(ds.findUlParent(it.first) == it.first) // it.first represent the node bcx it.second in 1;
            cnt++;
        }
        return n-cnt;
    }
};
