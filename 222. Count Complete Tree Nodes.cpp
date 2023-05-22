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
    void postOrder(TreeNode* root, int &n){
        if(root == NULL) return;
        postOrder(root->left,n);
        postOrder(root->right,n);
        n++;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int n=0;
        postOrder(root,n);
        return n;
    }
};
