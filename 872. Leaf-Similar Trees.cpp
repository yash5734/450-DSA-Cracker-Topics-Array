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
    void solve(TreeNode* root1, vector<int>&arr){
        if(root1->left == NULL && root1->right == NULL){
            arr.push_back(root1->val);
            return;
        }

        if(root1->left!=NULL)
        solve(root1->left,arr);
        if(root1->right!=NULL)
        solve(root1->right,arr);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>tree1;
        vector<int>tree2;

        if(root1 ==NULL || root2 == NULL) return false;
        if(root1 ==NULL && root2 == NULL) return true;

        solve(root1,tree1);
        solve(root2,tree2);

        for(int i=0;i<tree1.size();i++){
            cout<<tree1[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<tree2.size();i++){
            cout<<tree2[i]<<" ";
        }

        if(tree1.size() != tree2.size()) return false;
        for(int i =0;i<tree1.size();i++){
            if(tree1[i] != tree2[i]) return false;
        }
        return true;

    }
};
