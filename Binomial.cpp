struct node
{
    int key;
    int rank;
    node *next, *prev, *child;
}

node *head;

node* MergeTree(node *p1, node *p2)     //zakładamy identyczne h!
{
    if(p1->key < p2->key) p1 <-> p2;    //chcemy mieć p1 jako to większe, więc coby nie fikało
    if(p1->rank ==0) p1->child = p2;    //DZIĘKI ZAŁOŻENIU O IDENTYCZNYM h TO NIE ROBI PROBLEMU
    else
    {
        p2->prev = p1->child->prev;     // poprzednie z p2 to ostatnie z poddrzew p1
        p2->prev->next = p2;            // następne ostatneigo z poddrzew p1 to p2
        p1->child->prev = p2;           // ostatnie z poddrzew p1 to p2
    }
    p1->rank++;                         //p1 urosło
    return p1;
}

void Insert(int v)
{
    node *q = new node;
    q->key = v;
    q->next = NULL;
    q->prev = q;
    q->child = NULL;
    q->rank = 0;
    head = Union(head, q);
}

node* Union(node *l1, node* l2)
{
    node *p1 = l1;                      //wskaźnik na pierwszej liście
    node *p2 = l2;                      //wskaźnik na drugiej liście

    node *przeniesienie;

    int k=0;
    while(p1, p2)                       //jedziemy od najniższych
    {
        if //nie istnieje żadne z drzew o wysokości k
            //nie dorzucamy drzew o wysokości k
        if //na TYLKO jednej liście jest drzewo o wysokości k
            //wrzucamy
        if //na OBU listach jest drzewo o wysokości k
            //łączymy tamte i dostajemy drzewo o wysokości k+1
            //może być że trzeba połączyć k+1 z tamtym starym jeśli jest jakieś
            //generalnie recurs
        if  //jest k z jednej i k z przeniesienia z dwóch k-1;
            //też będzie tutaj przeniesienie
        if  //są dwa drzewa k na listach oraz jest jedno na przeniesieniu
            //łączymy np. te dwa z listy, wstawiamy to z przeniesienia na jego miejsce
            //przenosimy k+1


        k++;
    }
}

// node *DeleteMax()
// {
//     if (!head) return NULL;
//
//     node *p = head;
//     node *pMax = head;
//     while(p)
//     {
//         if (p->key > pMax->key) pMax=p;
//         p = p->next;
//     }
//
//
