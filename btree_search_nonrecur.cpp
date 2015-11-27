#include <this>

node *Search(node *root, int v)
{
  node *p = root;
  while(p)      //analogiczne do if !root
  {
    p->key[0] = -infinity;
    int i = p->k;

    while(p->key[i]>v)
    {     //czy on pomija klamry żeby oszczędzić miejsce w ksiązce?
      i--;
    }

    if(p->key[i]==v)
    {
      return p;
    }

    p = p->next[i];
  }
  //wyszliśmy z while (przejrzeliśmy wszystkie nexty, nie znaleźliśmy elementu)
  // i robimy to co było oryginalnie w !root
  return NULL;
}
