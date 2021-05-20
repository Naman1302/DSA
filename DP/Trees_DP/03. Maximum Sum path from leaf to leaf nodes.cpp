int res;
class Solution {
public:
    int solve(Node* root){
        if(!root)
            return 0;
        if(!root->left&&!root->right)
            return root->data;
        
        int l=solve(root->left);
        int r=solve(root->right);
        
        int temp;
        if(root->left&&root->right)
        {
            res=max(res,l+r+root->data);
            temp=max(l,r)+root->data;
        }
        else if(root->left)
            temp=root->data+l;
        else if(root->right)
            temp=root->data+r;
        
        return temp;
    }
    int maxPathSum(Node* root)
    {
        // code here
        if(!root)
            return 0;
        res=INT_MIN;
        int ans=solve(root);
        return res==INT_MIN? ans: res;
    }
};
