#include <stdio.h>
#include <iostream>
using namespace std;

#define N 5

void print(int* A)
{
  for(int i=0; i<N; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void InsertionSort(int* A)
{
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

int main()
{
  //N defined at beginning!!!!
  int A[] = {5, 4, 3, 2, 1};
  print(A);
  SelectionSort(A);
}
