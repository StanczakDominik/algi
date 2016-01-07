struct node
{
    int h;
    int key; //jeśli to jest element to to jest klucz, jeśli nie to jest to wartość maksymalna kluczy z poddrzewa
    node *left, *mid, *right;
}

void UnionR(node *p1, node *&p2, int lev, int dh)
{   //KONIECZNIE DO PRZEJRZENIA
    //drzewko 2 będzie wypuszczane
    //int lev - poziom, głębokość, liczone od góry
    //int dh - różnica wysokości drzew?
    if(lev<dh-1)        //????????????na takich mniej więcej zrównoważonych?
        UnionR(p1->right?p1->right:p1->mid,p2,lev+1,dh);    //jeśli pierwsze ma prawego następnika

    if(p2)          //jesli jest drugie drzewko
    {
        if(!p1->right)      //jesli piewrsze nie ma prawego następnika
        {
            p1->right = p2; //zastępujemy przez drugie drzewko tego prawego następnika
            p2 = NULL;      // czyścimy drugie drzewko
        }
        else
        {
            node *ptr = new node;       //tworzymy nowy korzeń
            ptr->left = p1->right;
            ptr->mid=p2;
            ptr->right = NULL;
            ptr->key = max(ptr->left->key, ptr->mid->key)
            p1->right = NULL;

            p2 = ptr;
        }
    }
    p1->key = max(p1->left->key, p1->mid->key);
    if(p1->right)
    {
        p1->key = max(p1->key, p1->right->key);
    }
}

node *Union(node *p1, node *p2)
{
    if(!p1) return p2;
    if(!p2) return p1;

    if(p1->h<p2->h)
    {
        node *ptr = p1;
        p1 = p2;
        p2 = ptr;
    }

    if (p1->h-p2->h>0)
    {
        UnionR(p1,p2,0,p1->h-p2->h);
    }

    if(p2)
    {
        node *ptr = new node;
        ptr->left = p1;
        ptr->mid = p2;
        ptr->right = NULL;
        ptr->key = max(ptr->left->key, ptr->mid->key);
        ptr->h = p1->h+1;

        p1 = ptr;
    }

    return p1;

}

int Max()
{
    return root->key;
}
node *GetMax()
{
    if(!root) return NULL;

    node *p = root;
    while(p->left)  //wszystko poza liśćmi ma lewego więc to jest wystarczający warunek na liścia
    {
        //bardzo rozsądne jak pomyśleć o tym co jest kluczami w 2-3+
        if(p->key==p->left->key) p = p->left;
        else if (p->key ==p->mid->key) p = p->mid;
        else if(p->right && p->key == p->right->key) p = p->right;  //w tej implementacji right nie zawsze musi wystąpić
    }
    return p;
}


node *DeleteMax()
{
    
}
