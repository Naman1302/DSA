class Solution {
private:
    int res;
public:
    int solve(TreeNode* root){
        //=======Base-Condition======
        if(root==NULL)
            return 0;
        //---------------------------
        
        //=======Hypothesis==========
            int l=solve(root->left);
            int r=solve(root->right);
        //---------------------------
        
        //=======Induction===========
            int temp=max(root->val,max(l,r)+root->val);
            int ans=max(temp,root->val+l+r);
            res=max(res,ans);
        //---------------------------
        
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        res=INT_MIN;
        solve(root);
        return res;
    }
};
