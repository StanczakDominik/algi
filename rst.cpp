#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define maxb 3

struct node
{
  int key;
  node *next[2];
};

int bit(int x, int i)
{
  return (x>>i)&1;
}

void print_bits(int keyue)
{
    int mask = 1 << (maxb-1);

    while (mask)
    {
        printf("%d", (mask & keyue) != 0);
        mask >>= 1;
    }
}

void postorder(node* p, int indent=0)
{
    if(p != NULL) {
        if(p->next[1]) {
            postorder(p->next[1], indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->next[1]) std::cout<<" /\n" << std::setw(indent) << ' ';
        // std::cout<< number_to_bit(p->key) << "\n ";
        std::cout<< p->key << "\n ";
        if(p->next[0]) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->next[0], indent+4);
        }
    }
}

void postorderbits(node* p, int indent=0)
{
    if(p != NULL) {
        if(p->next[1]) {
            postorderbits(p->next[1], indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->next[1]) std::cout<<" /\n" << std::setw(indent) << ' ';
        print_bits(p->key);
        cout << "\n ";
        if(p->next[0]) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorderbits(p->next[0], indent+4);
        }
    }
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
    printf("depth is %d, bit is %d\n", depth, this_bit);
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

void JDelete(int v)
{
    if (!root)
        return;

    node **p = Search(v);

    if (!(*p))
        return;

    node **pp = p;

    while( (*pp)->next[0] || (*pp)->next[1] )
    {
        if( (*pp)->next[0] )
            pp = &((*pp)->next[0]);
        else
            pp = &((*pp)->next[1]);
    }

    (*p)->key = (*pp)->key;
    delete *pp;
}

void Delete(int v)
{
  node **p = Search(v);
  if (!(*p)) return;

  node **pp = p;
  while(true)
  {
    if((*pp)->next[0])
    {
      (*pp) = (*pp)->next[0];
    }
    else if((*pp)->next[1])
    {
      (*pp) = (*pp)->next[1];
    }
    else break;
  }

  (*pp)->next[1] = (*p)->next[1];
  (*pp)->next[0] = (*p)->next[0];
  node *temp = *p;
  *p=*pp;
  delete temp;
}

void test_bits()
{
  for(int v=0;v<6;v++)
  {
    printf("%2d | %2d   %2d   %2d   %2d  |=  %2d\n", v, bit(v,0), bit(v,1), bit(v,2), bit(v,3), bit(v,0)+2*bit(v,1)+4*bit(v,2)+8*bit(v,3));
  }
}

int main()
{
  test_bits();
  int A[] = {1,2,3,4,5,6,7};
  for(int v=0;v<8;v++)
  {
    Insert(A[v]);
  }

  postorder(root);
  cout << "===========================" << endl;
  postorderbits(root);
  Delete(5);
  postorder(root);
  if (*(Search(7))==NULL)
  {
    cout << "nope" << endl;
  }
  else
  {
    cout << (*(Search(7)))->key << endl;
  }
}
