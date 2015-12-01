#include <iostream>
using namespace std;

struct node
{
  int val;
  int h;
  node* child;
  node* next;
  node* prev;
}

node* MergeTree(node* root1, node* root2)
{
  //assumes h = same
  if(root2->val > root1->val)
  {
    //swaps roots because top root must be higher in value than its children
    //root1 <-> root2
  }
  if(!(root1->child))
  {
    root1->child = root2;
    root1->h=1;
    return root1;
  }
  node* last = root1->child->prev;
  last -> next = root2;
  root2->prev = last;
  root1->prev = root2;
  root1->h++;
  return root1;
}

void PrintAll(node* root)
{
  //printuje dzieci
  cout << root->val;
  node *p = root->child;
  while(p)
  {
    PrintAll(p);
    p=p->next;
  }
}

node* Extract(node* &head)
{
  node *p=head;
  head = p->next;
  head->prev = p->prev;
  p->next = nullptr;
  p->prev = p;
  p->next = nullptr;
  return p;
}

void AddToLast(node* head, node* root)
{
  if(!head)
  {
    head=root;
    return;
  }
  node *last = head->prev;
  head->prev = root;
  last->next = root;
  root->prev = last;
}
