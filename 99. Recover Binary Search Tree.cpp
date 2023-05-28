// Method 1 TC = O(n Logn) ;

class Solution {
public:
    void compare(TreeNode* root,vector<int>v,int &i){
        if(root==NULL) return;
        compare(root->left,v,i);
        int temp = v[i++];
        if(root->val!=temp) root->val = temp;
        compare(root->right,v,i);
    }
    void inOrder(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        
        vector<int>v;
        inOrder(root,v);
        int i=0;
        sort(v.begin(),v.end());
        compare(root,v,i);
    }
};

Method 2 


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
    TreeNode* first;
    TreeNode* second;
    TreeNode* middle;
    TreeNode* prev;

    void inorder(TreeNode* root){
        if(root==NULL) return ;

        inorder(root->left);

        if(prev!=NULL&& root->val<prev->val){
            if(first ==NULL){
                first = prev;
                middle = root;
            }else{
                second = root;
            }

        }
            prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        first = second = middle = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first&&second) swap(first->val,second->val);
        else if(first&&middle) swap(first->val,middle->val);
    }
};

TC = 0<n>
