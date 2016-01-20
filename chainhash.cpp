#include <stdio.h>
#include <iostream>
using namespace std;

#define m 50
#define DELETED -1


struct node
{
  int key;
  node *next;
};

node* A[m];
int h(int v)
{
  return ((2015*v+42)%4663)%m;
}


node* Search(int v)
{
  node* p = A[h(v)];
  while(p && (p->key != v))
  {
    cout << p->key << "->"; //for fun
    p=p->next;
  }
  return p;
}

void Insert(int v)
{
  int i = h(v);
  if(!A[i])
  {
    A[i] = new node;
    A[i] -> key = v;
    A[i]->next = nullptr;
  }
  else
  {
    node *p = A[i];
    while(p->key != v && p->next)
    {
      p=p->next;
    }
    if(p->key != v)
    {
      node *q = new node;
      q->key = v;
      q->next = nullptr;
      p->next = q;
    }
  }
}

void Delete(int v)
{
  int i = h(v);
  if(!A[i]) return;
  node *p = A[i];
  if(A[i] ->key == v)
  {
    A[i] = p->next;
    delete p;
  }
  else
  {
    while(p->next && p->next->key != v)
    {
      p = p->next;
    }
    if(p->next)
    {
      node *q = p->next;
      p->next = q->next;
      delete q;
    }
  }
}

int main()
{
  for(int i =0; i<500; i++)
  {
    Insert(i);
  }
  cout << Search(5)->key << endl;
  cout << Search(7)->key << endl;
  cout << Search(8)->key << endl;
  Delete(7);
  cout << Search(7) << endl;
  Insert(7);
  cout << Search(7)->key << endl;
}
