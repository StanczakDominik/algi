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



node* Union(node *p1, node* p2)
{
    node *t1;                      //wskaźnik na pierwszej liście
    node *t2;                      //wskaźnik na drugiej liście
    //moznaby je wyzej zainicjalizowac NOale jest za duzo opcji zeby to bylo jakkolwiek przydatne
    node *przeniesienie;

    while(p1 || p2)                       //jedziemy od najniższych
    {
        if (!p1)//nie istnieje żadne z drzew o wysokości k
        {
            //nie dorzucamy drzew o wysokości k
            t1 = Extract(p2)
            t2 = NULL;
        }
        else if (!p2)
        {
            t1 = Extract(p1);
            t2 = NULL;
        }       //na tym etapie wiemy: są obydwa
        else if (p1->rank < p2->rank)
        {
            t1 = Extract(p1);
            t2 = NULL;
        }
        else if (p1->rank > p2->rank)
        {
            t1 = Extract(p2);
            t2 = NULL;
        }
        else
        {
            t1 = Extract(p1);
            t2 = Extract(p2);
        }
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

node *DeleteMax()
{
    if (!head) return NULL; //nie może niczego usunąć

    node *p = head; //pointer do searcha
    node *pMax = head;  //pointer na najwyższy element
    while(p)        //lecimy po wszystkich korzeniach
    {
        if (p->key > pMax->key) pMax=p; //zapisujemy max
        p = p->next;            //przechodzimy dalej
    }
    
    node *t = pMax->child;  //bierzemy poddrzewo maksymalnego
    
    if(pMax->next)          //jesli nie byl ostatnim
        pMax->next->prev=pMax->prev;    //obejście maksymalnego od strony przedniej
    else    //jesli byl ostatnim
        head->prev = pMax->prev; //gdyby lista byla cykliczna w obie strony nie musielibysmy robic special case.
                                //ale pMax->next = nie head a null
                                
    if(pMax!=head)          //jesli nie byl pierwszym
        pMax->prev->next=pMax->next;        //obejście maksymalnego od strony tylniej
    else                    //jesli byl pierwszym
        head=head->next;    //przesuwamy wskaznik na kolejnego bo ten wywalamy
    
    
    //wstawiamy poddrzewo usuniętego maksymalnego w jego odpowiednie miejsce w kolejce, tym juz sie martwi union
    head = Union(head, t);
    
    return pMax;
}

node *Extract(node *&head)  //wyciaganie pierwszego drzewa w danej kolejce ()
{
    node *p = head;
    head = head->next;  //przesunięcie wskaźnika
    if(head)
        head->prev = p->prev; //obejście wyciągniętego
        
    p->next = null; //chcemy zwrocic drzewko, nie kolejke, right?
    p->prev = null;
    return p;
}

void AddTree(node* t)
{
    if(!head) head = t;
    else
    {
        head->prev->next=t;
        //t->next=null; niepotrzebne gdy zalozymy ze dodajemy DRZEWKO NA KONIEC a nie KOLEJKE NA KONIEC;
                //tamto i tak jest bez sensu i trzeba by zrobic to przez UNION
        t->prev=head->prev;
        head->prev=t;
    }
}
