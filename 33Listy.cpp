#include <iostream>
using namespace std;

struct node
{
  int key;
  node *next;
};

node *head, *tail, *sentinel;
//must define sentinel, tail in build!

node *Search(int key)
{
    sentinel->key = key;
    node * ptr = head;
    while(ptr->key!=key)
    {
        ptr = ptr->next;
    }
    return  ptr==sentinel ? nullptr : ptr;
}

void Inject(int key)
{
    node *ptr = new node;
    ptr-> key = key;
    ptr->next = nullptr;
    if(!tail)
      head = ptr;
    else
      tail->next = ptr;
    tail = ptr;
}

void Build()//int* table)
{
  head = new node;
  head->key = 1;
  head->next = new node;
  head->next->key=3;
  head->next->next=new node;
  head->next->next->key=5;
  head->next->next->next = nullptr;
}

void BuildFromTable(int* table)
{
  head = new node;
  head->key = 1;
  head->next = new node;
  head->next->key=3;
  head->next->next=new node;
  head->next->next->key=5;
  head->next->next->next = nullptr;
}

int main()
{
  Build();
  cout << head->next->next->key << endl;

}
