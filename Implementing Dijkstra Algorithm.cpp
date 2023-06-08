class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        vector<int>dis(V,INT_MAX);
        dis[S] = 0;
        pq.push({0,S});
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int nWt = it[1];
                int nNode = it[0];
                if(wt+nWt <dis[nNode]){
                    dis[nNode] = wt+nWt;
                    pq.push({wt+nWt,nNode});
                }
            }
        }
        return dis;
    }
};
