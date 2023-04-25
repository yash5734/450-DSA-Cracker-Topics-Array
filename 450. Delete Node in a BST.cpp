class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return null;

        if(root.val == key){
            return helper(root);
        }
        TreeNode temp = root;
        while(root!= null){
            if(root.val>key){
                if(root.left!=null && root.left.val == key){
                    root.left = helper(root.left);
                    break;
                }
                else{
                    root = root.left;
                }
            }
            else{
                if(root.right !=null && root.right.val == key){
                    root.right = helper(root.right);
                    break;
                }
                else{
                    root = root.right;
                }
            }
        }
        return temp;
    }

    public static TreeNode helper(TreeNode root){
        if(root.left == null){
            return root.right;
        }
        else if(root.right==null){
            return root.left;
        }

        TreeNode rightChild = root.right;
        TreeNode leftRight = findright(root.left);
        leftRight.right = rightChild;

        return root.left;
    }

    public static TreeNode findright(TreeNode root){

     if(root.right==null) return root;

        return findright(root.right);   
    }
}
