class Solution {
public:
    int maxi =0;

    int leftheight(TreeNode* root){
        if(root == NULL) return 0;

        return 1+max(leftheight(root->left),leftheight(root->right));
    }
    int rightheight(TreeNode* root){
        if(root == NULL) return 0;

        return 1+max(rightheight(root->left),rightheight(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = leftheight(root->left);
        int rh = rightheight(root->right);

        maxi = max(maxi,lh+rh);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxi;
    }
};


// Time Complexity = O(N^2);



class Solution {
public:
    int solve(TreeNode* root,int &maxi){

        if(root == NULL) return 0;

        int lh = solve(root->left,maxi);
        int rh = solve(root->right,maxi);

        maxi = max(maxi,lh+rh);

        return 1+max(lh,rh);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        solve(root,maxi);
        return maxi;
    }
};

// Time Complexity = O(N);
