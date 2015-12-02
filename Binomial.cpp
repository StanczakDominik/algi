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
    node *last;

    while(p1 || p2)                       //jedziemy od najniższych
    {
        if (!p1)//pierwsza jest pusta
        {
            //bierzemy z drugiej
            t1 = Extract(p2)
            t2 = NULL;
        }
        else if (!p2)   //analogicznie odwrotnie
        {
            t1 = Extract(p1);
            t2 = NULL;
        }       //na tym etapie wiemy: są obydwa
        else if (p1->rank < p2->rank)
        {
            t1 = Extract(p1);           //jesli pierwsze drzewko w p1 jest mniejsze od pierwszego w p2
            t2 = NULL;                  //to bedziemy dodawac to z p1 do kolejki w biezacej iteracji
        }
        else if (p1->rank > p2->rank)   //jesli odwrotnie
        {
            t1 = Extract(p2);           //to analogicznie, na kazdym etapie dodajemy to z "mniejszej kolumny"
            t2 = NULL;
        }
        else                            //AKA ten sam rank wiec mamy dwa drzewa tego samego rodzaju
        {
            t1 = Extract(p1);           //odpinamy oba
            t2 = Extract(p2);           //odpinamy oba
        }

        // generalnie: t1 ma byc zawsze zapelnione, t2 moze byc do niego dodawane opcjonalnie
        if(last && last->rank<t1->rank) //jesli jest cos do przeniesienia i jest mniejsze od pierwszego z dodawanych drzew
        {
            AddTree(q, last); //wpychamy na początek kolejki
            last = NULL;
        }

        /////////////////////???????????????????
        //tu nie ma else if bo last moze byc mniejszy od t1?????
        if(!last && !t2)
        {
            AddTree(q, t1);
            //t1 = NULL; t1 oraz t2 nie są przenoszone między iteracjami
        }
        else if(!last) //jest t1, jest t2
        {
            last = MergeTree(t1, t2);
        }
        else if (!t2)   //jest t1, jest last
        {
            last = MergeTree(t1,last);
        }
        else            //jest dżefo
        {               //jest last
                        //się ścina
                        //się rżnie
                        //jest deska
                        //jest sęk
            last = MergeTree(last, t2);
            AddTree(q,t1);
        }
    }

    if(last)        //jesli cokolwiek zostalo z ostatniej iteracji do przeniesienia
    {
        AddTree(q,last);        //dopinamy na koniec kolejki
    }
    return q;
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
