class Solution{
    private:
    
    void dfs(int node, stack<int> &st, int vis[], vector<int>adj[]){
        vis[node]= 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,st,vis,adj);
            }
        }
        st.push(node);
    }
    
    vector<int> topoSort(int V,vector<int>adj[]){
        int vis[V] = {0};
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,st,vis,adj);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            
            for(int ptr = 0;ptr<len;ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo;
        topo = topoSort(K,adj);
        string ans = "";
        for(auto it:topo){
            ans = ans+ char(it+'a');   
        }
        
        return ans;
    }
};
