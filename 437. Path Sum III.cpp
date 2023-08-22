/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    void solve(TreeNode* root, vector<int>&vec, int &cnt, int k){

        if(root == NULL) return;

        vec.push_back(root->val);
        solve(root->left,vec,cnt,k);
        solve(root->right,vec,cnt,k);

        long long sum = 0;

        for(int i=vec.size()-1;i>=0;--i){
            sum += vec[i];
            if(sum==k)cnt++;
        }

        vec.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>vec;
        int cnt = 0;
        solve(root,vec,cnt,targetSum);
        return cnt;
    }
};
