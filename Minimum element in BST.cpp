int minValue(Node* root) {
    // Code here
    if(root == NULL) return -1;
    if(root ->left == NULL && root->right == NULL) return root->data;
    
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}
