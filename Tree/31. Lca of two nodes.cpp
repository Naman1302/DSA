class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node * lca(Node* root,int n1,int n2)
    {
    
      if(root==NULL)
        return NULL;
    
      //if either n1 or n2 matches with data at current node, we return root.
      // (Note that if a node is ancestor of other, then the ancestor node
      //becomes the lowest common ancestor).
      if(root->data==n1 or root->data==n2)
        return root;
        
      //calling the lca function recursively for left and right subtrees.
      Node *l = lca(root->left,n1,n2);
      Node *r = lca(root->right,n1,n2);
      
      //if both of the above calls return non-NULL value then one node
      //is present in one subtree and other is present in another subtree. 
      //So, this node is the lowest common ancestor.
      if (l and r)
        return root;
    
      //else we check if left subtree or right subtree is the
      //lowest common ancestor.
      return (l!=NULL)?l:r;
    }
};
