#include<bits/stdc++.h>
using namespace std;
class disJointSet{
    public:
    vector<int>rank,parent,size;
    disJointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = i;
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


    int main() {
    disJointSet ds(7);
    ds.unionByRank(1, 2); 
    ds.unionByRank(2, 3); 
    ds.unionByRank(4, 5); 
    ds.unionByRank(6, 7); 
    ds.unionByRank(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUlParent(3) == ds.findUlParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionByRank(3, 7); 

    if(ds.findUlParent(3) == ds.findUlParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
}


// https://ide.geeksforgeeks.org/online-cpp14-compiler/fba42d64-2cd9-449a-91bb-fbb7a7108023
