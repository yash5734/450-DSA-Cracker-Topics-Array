class Solution {
public:
    bool isLeaf(Node *root){
        return !root->left && !root->right;
    }
    
    void leftSubTree(Node *root, vector<int>&ans){
        Node *curr = root->left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
        
    }
    void leafNode(Node *curr, vector<int>&ans){
        if(isLeaf(curr)){
            ans.push_back(curr->data);
            return;
        }
            
            
        if(curr->left) leafNode(curr->left,ans);
        if(curr->right) leafNode(curr->right,ans);
    }
    void rightSubTree(Node *root, vector<int>&ans){
        Node *curr = root->right;
        vector<int>temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        for(int i=temp.size()-1;i>=0;--i){
            ans.push_back(temp[i]);
        }
    }

    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        
        leftSubTree(root,ans);
        leafNode(root,ans);
        rightSubTree(root,ans);
        
        return ans;
    }
};
