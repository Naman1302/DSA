/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* building(int in[],int li,int ri,int post[],int lp,int rp,unordered_map<int,int> &m){
  
  //if anytime we slip out our boundings  
  if(li>ri||lp>rp) return NULL;
  //create a node of tree whose root will be at postEnd of Post[]  
  Node* root= new Node(post[rp]);
  //finding it in inorder traversal to get idea of elements in left and right subtree  
  int inr=m[root->data];
  //now to get nuber of elements in left subtree so that we can have idea in post[] of element breakdown
  int numl=inr-li;
  // this will get all the elements in left subtree as in[] has inStart to inRoot-1 in left while post has postStart to postStart+numLeft-1 as all numLeft are in left subtree  
  root->left=building(in,li,inr-1,post,lp,lp+numl-1,m);
  // this will get all the elemments in the right subtree as in[] has inRoot+1 to inEnd while post[] has that in postStart+numLeft to postEnd-1(as postEnd has root)     
  root->right=building(in,inr+1,ri,post,lp+numl,rp-1,m);
  //now return the node finally as it has left and right subtrees  
  return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    unordered_map<int,int> m;//for easy retrival of data
    for(int i=0;i<n;i++){
        m[in[i]]=i;
    }
    //Initiation of root Node
    Node* root=building(in,0,n-1,post,0,n-1,m);
    return root;
}
