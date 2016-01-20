#include <stdio.h>
#include <iostream>
using namespace std;
#define No 3
#define N 19
int A[] = {3,1,2,1,2,3,3,1,2,3,1,2,3,1,2,3,3,2,1};
int o[] = {1, 2, 3};

void print(int* A)
{
  for(int i=0; i<N; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void print(int* A, int l, int r)
{
  for(int i=l; i<r; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void CountSort()
{
  int no[No] = {0};

  for (int i = 0; i<N; i++)
  {
    no[A[i]-1]++;
  }
  int total =0;
  for (int j=0; j<No; j++)
  {
    int oldCount = no[j];
    no[j] = total;
    total += oldCount;
  }

  int j = No-1;
  for(int i = N-1; i>=0; i--)
  {
    if(i < no[j]) j--;
    A[i] = o[j];
  }
}

int main()
{
  print(A);
  CountSort();
  print(A);
}
