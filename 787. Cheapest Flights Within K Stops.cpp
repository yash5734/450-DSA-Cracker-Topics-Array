class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int  V = flights.size();
        vector<pair<int,int>>adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        dist[src] = 0;

        queue<pair<int,pair<int,int>>>q;  
        q.push({0,{src,0}});

        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();

            if(stop>k) continue;

            for(auto it:adj[node]){
                int nNode = it.first;
                int nDis = it.second;
                if(dis+nDis < dist[nNode] && stop<=k){
                    dist[nNode] = dis+nDis;
                    q.push({stop+1,{nNode,dis+nDis}});
                }
            }
        } 
        if(dist[dst] == 1e9) return -1;
        return dist[dst];   

    }
};
