class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        int indegree[V];
        for(int i=0;i<V;i++){
            indegree[i] = 0;
        }

        vector<int>adjRev[V];
        for(int i=0;i<V;i++){
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(auto it:adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
return ans;

    }
};
