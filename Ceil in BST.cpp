int findCeil(Node* root, int input) {
    int ceil = -1;
    if (root == NULL) return -1;

    while(root){
        if(root->data<input){
            root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}
