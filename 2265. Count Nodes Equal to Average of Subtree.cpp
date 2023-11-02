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
    pair<int,int>solve(TreeNode* root, int &count){

        // base condition
        if(root == NULL){
            return {0,0};
        }

        pair<int,int>left = solve(root->left,count);
        pair<int,int>right = solve(root->right,count);

        int sum = left.first + right.first + root->val;
        int num = left.second + right.second + 1;

        if(sum/num == root->val){
            count++;
        }

        return {sum,num};

    }

public:
    int averageOfSubtree(TreeNode* root) {
        int count =0;
        solve(root,count);
        return count;
    }
};
