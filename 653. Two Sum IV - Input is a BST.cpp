class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    bool findTarget(TreeNode* root, int target) {
        map<int, int> mpp;
        vector<int> v;
        inorder(root, v);
        for (int i = 0; i < v.size(); i++) {
            mpp[v[i]] = i;
        }

        if (v.size() == 1) return false;

        for (int i = 0; i < v.size(); i++) {
            int temp = target - v[i];
            if (mpp.find(temp) != mpp.end() && mpp[temp] != i) {
                return true;
            }
        }
        return false;
    }
};
