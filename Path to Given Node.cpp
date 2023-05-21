 bool fun(TreeNode* root, vector<int>&ans,int key){
     if(root== NULL) return false;
     
     ans.push_back(root->val);
     if(root->val==key) return true;
     
     if(fun(root->left,ans,key)) return true;
     else if(fun(root->right,ans,key)) return true;
     
     ans.pop_back();
     return false;
 }
 
vector<int> Solution::solve(TreeNode* A, int B) {

vector<int>ans;
if(A==NULL) return ans;
fun(A,ans,B);
return ans;

}
