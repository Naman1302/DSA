class Solution
{
    public:
    int solve(Node* root,int &d){
      //====Base Condition===//
      
      if(!root) return 0; 
      
      //=====================//
      
      //====Hypothesis=======//
      
      //#NEVER_QUESTION_HYPOTHESIS
      int l=solve(root->left,d);
      int r=solve(root->right,d); //=>gives us depth of each left and right binary sub-tree
      
      //=====================//
      
      //====Induction========//
      
        int temp=1+max(l,r); //if our taken node is not the path from left to right subtree for dia. it transfers value to it's root by maximising it's dia. and +1
        int ans=max(temp,1+l+r);//if our taken node is the path from left to right subtree for dia. , it maximises it's dia and dia going to top if it isn't
        d=max(d,ans);//maximising dia.
      
      //=====================//  
        return temp; // returning temp to root the case where our node don't wanna be the root
    }
    int diameter(Node* root)
    {
        int d=INT_MIN;
        solve(root,d);
        return d;
    }

};
