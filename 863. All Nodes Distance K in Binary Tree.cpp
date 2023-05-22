class Solution {
public:

    void mark_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                parent_track[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent_track[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        mark_parent(root,parent_track);

        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target] = true;
        int dist = 0;

        while(!q.empty()){
            int size = q.size();
            if(dist++ == k) break;

            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                // check for left node
                if(curr->left && !vis[curr->left]){
                    vis[curr->left] = true;
                    q.push(curr->left);
                }

                // check for right node
                if(curr->right && !vis[curr->right]){
                    vis[curr->right] = true;
                    q.push(curr->right);
                }

                // check for parent node
                if(parent_track[curr] && !vis[parent_track[curr]]){
                    vis[parent_track[curr]] = true;
                    q.push(parent_track[curr]);
                }
            }
        }

        vector<int>ans;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }

        return ans;
    }
};
