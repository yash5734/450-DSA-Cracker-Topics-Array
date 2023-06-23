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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        sort(accounts.begin(),accounts.end());// sort bcz given question
        int n = accounts.size();
        disJointSet ds(n);
        unordered_map<string,int>mp; // map is used to store the mail index wise by this we can find weather the given
        for(int i=0;i<n;i++){ //mail is previously visited aur not if the mail is priviously viited then we can join 
            for(int j=1;j<accounts[i].size();j++){ //the component as we have created the n size compo by disjoint
                string mail = accounts[i][j]; // by joining the compo we can easly concatenate as we push the mail 
                if(mp.find(mail)==mp.end()){ // to the ultimate parent index
                    mp[mail] = i;
                }
                else{
                    ds.unionByRank(i,mp[mail]);
                }
            }
        }

        // this portion is used to create the list by using map
        vector<string>mergedList[n];
        for(auto it: mp){
            int node = ds.findUlParent(it.second);
            mergedList[node].push_back(it.first);
        }
        
        // this will ans
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){

            if(mergedList[i].size()==0) continue; // it meand that the given index list does not have mail
            sort(mergedList[i].begin(),mergedList[i].end());
            vector<string>temp; // it is used to store the  mail index wise;
            temp.push_back(accounts[i][0]); // account[i][0] = name first push the name and the oush the mail 
            for(auto it:mergedList[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};
