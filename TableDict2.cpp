#include <iostream>
using namespace std;

int A[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
int iLast=25;

int Search(int v)
{
    int i =0;
    int j = 25;
    while (i<=j)
    {
        int k = (i+j)/2;
            cout << i << " " << j << " " << k << endl;
        if (A[k]>=v) j = k-1;
        if (A[k]<=v) i = k+1;
    }
    if(i>j+1) return j+1;
    else return -1;
}

int main()
{
    cout << Search(9) << endl;
}
