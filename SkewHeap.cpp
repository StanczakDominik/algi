struct node
{
    int key;
    node *left, *right;
};

node *root;

node *Union(node *p1, node *p2)
{
    if(!p1) return p2;
    if(!p2) return p1;

    if(p1->key > p2->key)
    {
        p=p1;
        p->right = Union(p1->right, p2);
    }
    else
    {
        p=p2;
        p->right = Union(p2->right, p1);
    }

    node *q=p->left;
    p->left=p->right;
    p->right=q;

    return p;
}

void Insert(int v)
{
    int *p = new node(key = v, left = right = null, npl = 0);
    root = Union(root, p);
}

node *DeleteMax()
{
    node *pMax = root;
}
