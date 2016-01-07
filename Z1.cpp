#include <iostream>
#include <stdio.h>
using namespace std;


const int N = 15;
int A[N];
void DownHeap(int i, int N, int *A)
{
    // pesymistyczna O(log_2 N)
    int k = 2*i+1;
    int v = A[i];
    while (k<N)
    {

        //debug
        cout << "iter" << endl;
        for (int j=0; j<N; j++) printf("%4d", j);
        cout << endl;
        for (int j=0; j<N; j++) printf("%4d", A[j]);
        cout << endl;



        if(A[k+1]<A[k])
        {
            k++;
        }
        if(v > A[k])
        {
            A[i] = A[k];
            i = k;
            k=2*i+1;
        }
        else
        {
            break;
        }
        printf("%4d %4d", i, k);
        cout << endl;
    }
    A[i]=v;
}

void Insert(int v, int &hl)
{
    hl++;
    A[hl]=v;

}

int main()
{
    int A[] = {40, 5, 6, 7, 14, 18, 9, 8, 9, 15, 18, 30, 20, 30, 25};
    hl = 15;
    DownHeap(0, hl, A);
    cout << "end" << endl;
    for (int j=0; j<N; j++) printf("%4d", A[j]);
    cout << endl;
}
