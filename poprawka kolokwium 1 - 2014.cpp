Węzeł drzewa dwumianowego

struct node
{
    int key;
    int h;
    node *child, *prev, *next;
}
node *head;


void AddTreeToQueue(node *tree)
{
    int h = tree->h;
    node *p = head;
    if(!p) head = tree;
    while(p->h<h)
    {
        p = p->next;
    }
    if(p->next->h == h) p->next = MergeTree(Extract(p), tree);
    else
    {
        tree->prev = p->prev;
        tree->next = p;
        p->prev = tree;
    }
}

Kolejka priorytetowa to ADT jest rozszerzeniem zwykłej kolejki lub stosu, w którym każdy element ma własny priorytet. Elementy są zazwyczaj usuwane z kolejki w kolejności według najwyższego priorytetu.


2.
node **Search(node *elem)
{
    int b = rand() %2; //0 lub 1
    node **p;
    if(b) //idziemy w prawe poddrzewo
    {
        p = &(elem->right);
        while((*p)->left)
        {
            p = &((*p)->left);
        }
    }
    else
    {
        p = &(elem->left);
        while((*p)->right)
        {
            p=&((*p)->right);
        }
    }
    return p;
}

Złożoność rzędu O(h(poddrzewa)) przez konieczność przejścia na dno kopca, co daje O(log(h_p)).

3. Zrównoważenie dla AVL, przy założeniu że spełniamy wszystkie warunki zwykłych BST:
    współczynnik balansu równy wysokości lewego poddrzewa minus wysokości prawego poddrzewa równy -1, 0, lub 1 W KAŻDYM ELEMENCIE
dla drzew CC.
    każda ścieżka od dowolnego node do nulla zawiera taką samą liczbę czarnych node'ów.
    (pozostałe warunki: wszystkie nulle czarne, czerwony ma czarne dzieci, root jest czarny)
Złożoność inserta w AVL: ograniczona od góry przez 1.44logn, ogólnie logn.
Złożoność w 2-3-4: pesymistyczna 2logn, około logn średnia




Przykładowe zadania na słowniki

void InsertToPageR(node *root, int &v, node *&pr)
{
    
}
