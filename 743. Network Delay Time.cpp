class Solution {
private:
    vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, INT_MAX);
        dis[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            for (auto it : adj[node]) {
                int nWt = it.second;
                int nNode = it.first;

                if (wt + nWt < dis[nNode]) {
                    dis[nNode] = wt + nWt;
                    pq.push({wt + nWt, nNode});
                }
            }
        }

        return dis;
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];

        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist = dijkstra(n + 1, adj, k);

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            res = max(res, dist[i]);
        }

        return res;
    }
};
