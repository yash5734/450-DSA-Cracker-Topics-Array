class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            return new TreeNode(val);     
        }
        TreeNode* curr = root;
        while(true){
            
            if(root->val > val){
                if(root->left!=NULL) root = root->left;
                else{
                    root->left = new TreeNode(val);
                    break;
                }
            }
            else {
               if(root->right!=NULL) root = root->right;
                else{
                    root->right = new TreeNode(val);
                    break;
                }
                
            }
        }

        // root = curr;
        return curr;

        
    }
};
