struct node
{
    int key;
    node *left, *right;
}

node *Search(int v, node *&last)
{
    node *ptr = root;
    last = NULL;
    while(ptr && ptr->key !=v)
    {
        last = ptr;
        if(v > ptr->key) ptr = ptr->right;
        else if(v<ptr->key) ptr = ptr->left;
    }
    return ptr;
}

void Insert(int v)
{
    node *last = NULL;
    if(Search(v, last)) return;

    node *ptr = new node;
    ptr->key = v;
    ptr->left = ptr->right = NULL;

    if(!last) root = ptr;
    else
    {
        if(v>last->key) last->right=ptr;
        else last->left=ptr;
    }
}

node **Search(int v)
{
    node **p = &root;
    while((*p) && (*p)->key != v)
    {
        if (v > (*p)->key) p = &((*p)->right);
        else p = &((*p)->left);
    }
    return p;
}

void Insert(int v)
{
    node **ptr = Search(v);
    if(*ptr) return;
    node *p = new node;
    p ->key = v;
    p->left = p->right = NULL;

    *ptr = p;
}

void Construct()
{
    root = NULL;
}


void Delete(int v)
{
    node **p = Search(v);
    node **q;
    node *t;
    if ((*p)->right && (*p)->left)
    {
        int b = randint(0,2);
        q = p;
        if(b)
        {
            while((*q)->right)
                q=&((*q)->right);
            t=q->left;
        }
        else
        {
            while((*q)->left)
                q=&((*q)->left);
            t=*q;
            (*p)->key=t->key;
            *q
        }
    }
    else if (((*p)->right) && !((*p)->left))
    {
        *p = (*p)->right);
    }
    else if (((*p)->left) && !((*p)->right))
    {
        *p = (*p)->left);
    }
    else
    {
        *p = NULL;
    }
}
