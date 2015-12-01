struct node
{
    int key;
    node *left, *right;
    int npl;
};
node *root;

node *Union(node *p1, node *p2)
{
    if(!p1) return p2;      //nie ma co łączyć
    if(!p2) return p1;      //nie ma co łączyć

    if (p1->key > p2->key)  //który ma większego roota w tym związku?
    {
        p = p1;             //bierzemy roota jako szczyt
        p->right = Union(p1->right, p2);    // łączymy łączymy prawe poddrzewo większego z mniejszym
    }
    else
    {
        p = p2;
        p->right = Union(p2->right, p1);
    }
    //jeśli: a) nie ma lewego LUB b) prawemu dalej do roota niż lewemu
    if(!p->left || p-> left -> npl < p-> right->npl)    //czyli jeśli prawe jest większe
    {
        node *q = p->left;
        p->left = p->right;
        p->right = q;
    }

    //jeśli nie ma prawego to root ma zerową drogę do nulla, nie?
    if(!p->right) p->npl = 0;
    //jeśli jest prawy, i prawy jest mniejszy od lewego, a jest bo to LH, to tędy do nulla
    else p->npl = p->right->npl+1;

    return p;
}

void Insert(int v)
{
    node *p = new node(key = v, left = right = null, npl = 0);
    root = Union(root, p);
}

node *DeleteMax()
{
    node *pMax = root;
    root = Union(root->left, root->right);
    return pMax;
}

int Max()
{
    return root->key;
}
