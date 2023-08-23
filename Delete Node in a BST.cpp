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
    TreeNode* find(TreeNode* root){
        if(root->right==NULL) return root;

        return find(root->right);  

    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* extremeLeft = find(root->left);
        extremeLeft->right = rightChild;

        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key) return helper(root);
        TreeNode* head = root;

        while(root){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left = helper(root->left);
                    return head;

                }else{
                    root = root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right = helper(root->right);
                    return head;

                }else{
                    root = root->right;
                }
            }
        }
        return head;
        
    }
};
