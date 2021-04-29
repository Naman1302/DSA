bool isPairPresent(struct Node *root, int target)
{
    stack<Node *> s1, s2;
    Node *rootFwd = root, *rootBwd = root;
    // first look into inorder traversal without recursion on geeks for geeks
    
    // rootFwd does normal inorder traversal
    // rootBwd does reverse inorder traversal
    // now the question converts to two pointer solution for an array
    while (1)
    {
        if (rootFwd)
        {
            s1.push(rootFwd);
            rootFwd = rootFwd->left;
        }
        else if (rootBwd)
        {
            s2.push(rootBwd);
            rootBwd = rootBwd->right;
        }
        else if (s1.size() && s2.size())
        {
            rootFwd = s1.top();
            rootBwd = s2.top();
            if (rootFwd->data > rootBwd->data)
                return false;
            if (rootFwd == rootBwd)
                return false;
            if (rootFwd->data + rootBwd->data == target)
                return true;
            else if (rootFwd->data + rootBwd->data < target) // FwdItr++;
            {
                rootFwd = rootFwd->right;
                s1.pop();
                rootBwd = NULL; // this is necessary so that next time we come to this "else if" part and not the first "else if" part
            }
            else if (rootFwd->data + rootBwd->data > target)
            {
                rootBwd = rootBwd->left;
                s2.pop();
                rootFwd = NULL; // this is necessary so that next time we come to this "else if" part and not the first "if" part
            }
        }
        else
            return false;
    }
}
