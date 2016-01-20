#include <stdio.h>
#include <iostream>
using namespace std;

#define N 6
int A[] = {0, 6,5,4,3,2,1};
// #define N 15
// int A[] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 11, 5, 3, 2, 1};

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
void InsertionSort(int* A)
{
  //początek posortowany lokalnie w czasie
  for(int i=1; i<N; i++)
  {
    int v = A[i];
    int j = i-1;
    while(A[j]<v)
    {
      j--;
    }
    cout << j << endl;
    swap(A[i],A[j]);
    print(A);
  }
}
void BubbleSort(int* A)
{
  //iterujemy po wszystkich elementach
  for(int i = 0; i< N; i++)
  {
    cout << i << endl;
    //iterujemy po coraz krótszych trajektoriach
    //zależność od i jest dlatego, że
    //i=0 umieszcza A[0] na swoim prawidłowym miejscu
    //i=1 umieszcza A[1] na swoim prawidłowym miejscu
    //no i nie trzeba już tam się bawić
    for(int j = 0; j<N-i-1; j++)
    {
      if(A[j] > A[j+1])
      {
        swap(A[j], A[j+1]);
      }

      print(A);
    }
  }
}


//SelectionSort
//Rozpisać na kartce i sprawdzić stabilność
//On^2 porównań
//On przestawień
//dobry kiedy przestawienia są drogie (tzn nie tutaj)

void SelectionSort(int * A)
{
  for(int i=0; i<N-1; i++)
  {
    int min = 99999;
    unsigned int min_index = 0;
    for(int j = i; j<N; j++)
    {
      cout << i << " " << j << " ";
      if(A[j] < min)
      {
        cout << "swap ";
        min = A[j];
        min_index = j;
      }
      cout << endl;
    }
    swap(A[min_index], A[i]);
    print(A);
  }
}

// int Partition(int* A, int L, int R);
//
// void QuickSort1(int* A, int L, int R)
// {
//   int j = Partition(A, L, R);
//   QuickSort1(A,L,j-1);
//   QuickSort1(A,j+1, R);
// }
//
// void QuickSort2(int* A, int L, int R)
// {
//   while(L<R)
//   {
//     int j = Partition(A, L, R);
//     if(j-L < R-j)
//     {
//       QuickSort2(A, L, j-1);
//       L=j+1;
//     }
//     else
//     {
//       QuickSort2(A,j+1,R);
//       R=j-1;
//     }
//   }
// }

// void QuickSortNR(int*A)
// {
//   stack S;
//   S.push(1, n);
//   while(!(S.empty()))
//   {
//     l, S = S.pop(


void Merge(int* A, int l, int d1, int d2)
{
  int Nd = d1+d2;
  int B[d1+d2];
  int i = 0;
  int i1 = l;
  int i2 = l+d1;
  for(int i =0; i<d1+d2; i++)
  {
    printf("i %d Ai1 %d Ai2 %d ", i, A[i1], A[i2]);
    if(i1 < l+d1 && A[i1]<A[i2])
    {
      printf("taking %d\n", A[i1]);
      B[i] = A[i1];
      i1++;
    }
    else if (i2 < l+d1+d2)
    {
      printf("taking %d\n", A[i1]);
      B[i] = A[i2];
      i2++;
    }
  }
  cout << "merged";
  print(B, 0, d1+d2);
  for (int i =0; i<d1+d2; i++)
  {
    A[l+i] = B[i];
  }
}



void MergeSort(int* A, int l, int r)
{
  print(A, l, r);
  if (l==r)
  {
    cout <<"sorted";
    return;
  }
  int m = (l+r)/2;
  print(A, l, m);
  MergeSort(A,l,m);
  print(A, m+1, r);
  MergeSort(A, m+1, r);
  Merge(A, l, m-l, r-m);
}

// void MergeSortNR(int* A)
// {
//   // stack S;
//   // S.push(
// }

void HeapSort(int* A);
// {
  // while(
// }

int main()
{
  // int A[] = {1, 2, 3, 4};
  // Merge(A,0, 2, 2);
  // print(A, 0, 4);
  //N defined at beginning!!!!
  // print(A);
  MergeSort(A, 1, N+1);
  // print(A);
}
