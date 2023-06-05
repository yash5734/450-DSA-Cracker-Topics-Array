// using topo sort which uses dfs

class Solution
{
    private:
    void dfs(int node, int vis[], stack<int>&st, vector<int>adj[]){
        vis[node] =1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,vis,st,adj);
        }
        st.push(node);
        
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>st;
	    int vis[V] = {0};
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,st,adj);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

// using kahn's algo which uses bfs traversal

class Solution
{
	public:
	// using kahn's algo
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int inDegree[V] = {0};
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]){
	            inDegree[it]++;
	        }
	    }
	    
	    vector<int> topo;
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(inDegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it:adj[node]){
	            inDegree[it]--;
	            if(inDegree[it]==0) q.push(it);
	        }
	    }
	    return topo;
	}
};
