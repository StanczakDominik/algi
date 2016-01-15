#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
#define maxb 31

struct node
{
  int key;
  node *next[2];
};

//adapted from http://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way
void postorder(node* p, int indent=0)
{
    if(p != NULL) {
        if(p->next[0]) postorder(p->next[0], indent+4);
        if(p->next[1]) postorder(p->next[1], indent+4);
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        cout<< p->key << "\n ";
    }
}



int bit(int x, int i)
{
  return (x>>i)&1;
}

node *root;





node **Search(int v)
{
  int b = maxb;
  node **p = &root;

  int depth=0;

  while((*p) && (*p)->key!=v)
  {
    depth++;
    int this_bit = bit(v,b--);
    cout << this_bit << endl;
    p = &((*p)->next[bit(v,b--)]);
  }
  printf("looking for %4d, depth: %d\n", v, depth);
  return p;
}

void Insert(int v)
{
  node **p = Search(v);
  if (*p) return;

  *p = new node;
  (*p)->key=v;
  (*p)->next[0] = (*p)->next[1] = NULL;
}


int main()
{
  int A[] = {1,2,4,8,3,5,6,7};//{4, 7, 9, 11, 8, 2};
  for(int v=0;v<6;v++)
  {
    Insert(A[v]);
    printf("%2d\n", (*Search(A[v]))->key);
    // printf("%2d | %2d   %2d   %2d   %2d  |=  %2d\n", v, bit(v,0), bit(v,1), bit(v,2), bit(v,3), bit(v,0)+2*bit(v,1)+4*bit(v,2)+8*bit(v,3));
  }

  postorder(root);
  Search(100);
}
