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
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        
        int maxi =INT_MIN;
        int level = 0;
        int ans =0;
        q.push(root);

        while(!q.empty()){
            
            
            level++;

            int size = q.size();
            int sum =0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                sum+=node->val;
                q.pop();

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            }
            if(maxi<sum){
                maxi = sum;
                ans = level;
            }


        }
        return ans;

    }
};
