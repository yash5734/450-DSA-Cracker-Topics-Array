class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        queue<node*>q;
        q.push(root0);
        int i=1;
        while(i<vec.size()){
            node* temp = q.front();
            q.pop();
            temp->left = newNode(vec[i++]);
            q.push(temp->left);
            temp->right = newNode(vec[i++]);
            q.push(temp->right);
        }
    }

};
