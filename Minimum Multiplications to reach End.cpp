class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        queue<pair<int,int>>q;
        q.push({0,start});
        vector<int>dist(100000,1e9);
        dist[start] = 0;
        
        while(!q.empty()){
            int node = q.front().second;
            int dis = q.front().first;
            q.pop();
            
            for(auto it:arr){
                int nNode = (node*it)%100000;
                if(dist[nNode]>dis+1){
                    dist[nNode] = dis+1;
                  
                    if(nNode==end) return dis+1;
                
                    q.push({dis+1,nNode});
                }
            }
        }
        return -1;
    }
};
