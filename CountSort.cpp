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

void CountSort2()
{
  int count[No] = {0};
  print(count, 0, 3);
  for (int i =0; i<N; i++)
  {
    count[A[i]]++; //moze sie wysypac
  }
  print(count,0,3);
  for (int i=1 ; i<No; i++)
  {
    count[i] += count[i-1];   //cumulative sum
  }
  print(count,0,3);
  for (int i=N-1; i>0; i--)
  {
    printf("i %d\t A[i] %d\t count[A[i]] %d\n", i, A[i], count[A[i]]);
    int x = count[A[i]]--;
  }
  cout << "dwie" << endl;
  print(count,0,3);
}

int main()
{
  print(A);
  CountSort();
  print(A);
}
