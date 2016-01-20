#include <stdio.h>
#include <iostream>
using namespace std;

#define m 1000
#define DELETED -1

int A[m];
int h(int v)
{
  return ((2015*v+42)%4663)%m;
}


int Search(int v)
{
  int i = h(v);
  if (A[i] ==v) return i;
  else return DELETED; //not found
}

void Insert(int v)
{
  A[h(v)] = v;
}

void Delete(int v)
{
  A[h(v)] = DELETED;
}

int main()
{
  Insert(5);
  Insert(7);
  cout << Search(5) << endl;
  cout << Search(7) << endl;
  cout << Search(8) << endl;
  Delete(7);
  cout << Search(7) << endl;
  Insert(7);
  cout << Search(7) << endl;
}
