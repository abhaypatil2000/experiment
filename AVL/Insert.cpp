struct node
{
    int val;
    node * left;
    node * right;
    int ht;
    node(int val)
    {
        this -> val = val;
        left = NULL;
        right = NULL;
        ht = 0
    }
    node()
    {
        this -> val = 0;
        left = NULL;
        right = NULL;
        ht = 0;
    }
};
//height of a leaf node is 0 and that of external node is -1
//this can be changed in the line 3 of int height, line 3 in int balance, line 5 in node * insertnode, ht in both constructors
//It is assumed that all nodes are different
int height(node * root)
{
    if (root == NULL)
    {
        return -1;
    }
    return root -> ht;
}

int balance(node * root)
{
    if (root == NULL)
        return 0;
    return (height(root -> left) - height(root -> right));
}

node * insertnode(int x)
{
    node * temp = new node();
    temp -> val = x;
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> ht = 0;
    return temp;
}

node * rright(node * root)
{
    node * temp = root -> left;
    root -> left = temp -> right;
    temp -> right = root;
    root -> ht = 1 + max(height(root -> left), height(root -> right));
    temp -> ht = 1 + max(height(temp -> left), height(temp -> right));
    return temp;
}

node * rleft(node * root)
{
    node * temp = root -> right;
    root -> right = temp -> left;
    temp -> left = root;
    root -> ht = 1 + max(height(root -> left), height(root -> right));
    temp -> ht = 1 + max(height(temp -> left), height(temp -> right));
    return temp;
}

node * rleftright(node * root)
{
    root -> left = rleft(root -> left);
    return rright(root);
}

node * rrightleft(node * root)
{
    root -> right = rright(root -> right);
    return rleft(root);
}

node * insert(node * root, int val)
{
	if (root == NULL)
    {
        return insertnode(val);
    }
    else if (val > root -> val)
    {
        root -> right =  insert(root -> right, val);
    }
    else 
    {
        root -> left = insert(root -> left, val);
    }
    root -> ht = 1 + max(height(root -> left), height(root -> right));
    
    node * temp = root;
    if (balance(root) > 1)
    {
        if (balance(root -> left) == -1)
            temp = rleftright(root);
        else
            temp = rright(root);
    }
    else if (balance(root) < -1)
    {
        if (balance(root -> right) == 1)
            temp = rrightleft(root);
        else
            temp = rleft(root);
    }
    return temp;
}
