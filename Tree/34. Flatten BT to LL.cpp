//Recursive
class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(!root) return NULL;
        TreeNode* l= helper(root->left);
        TreeNode* r = helper(root->right);
        if(l!=NULL){
            TreeNode* temp=l;
            while(temp->right){
                temp=temp->right;
            }
            temp->right=r;
            root->right=l;
        }else
        root->right=r;
        root->left=NULL;
        return root;
    }
    void flatten(TreeNode* root) {
        if(!root) return;
          root=helper(root);
    }
};
