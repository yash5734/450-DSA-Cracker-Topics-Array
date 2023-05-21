 void solve(Node* root,vector<vector<int>>&ans,vector<int>ds){
     
     if(root == NULL) return;
     ds.push_back(root->data);
     if(root->left ==NULL && root->right == NULL){
        ans.push_back(ds);
        
     }
     else{
         solve(root->left,ans,ds);
         solve(root->right,ans,ds);
         ds.pop_back();
     }
     
 }
 
vector<vector<int>> Paths(Node* root)
{
    // Code 
    vector<int>ds;
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    if(root==NULL) return ans;
    solve(root,ans,ds);
    return ans;
}
