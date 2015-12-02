#include <iostream>
using namespace std;

int A[n];   //n rozmiar tablicy - odpowiednio większy
int iLast;  //ostatni element w słowniku


//w nieuporządkowanej tablicy
int Search(int v)
{
    A[iLast+1]=v;
    int i=0;
    while(A[i]!=v)
    {
        i++;
    }

    if (i<=iLast) return i;
    else return -1;

}

void Insert(int v)
{
    if(Search(v)>-1) return;
    else
    {
        iLast++;
        A[iLast]=v;
    }
}

void Delete(int v)
{
    int found_index = Search(v);
    if(found_index>-1) return;
    else
    {
        A[found_index]=A[iLast];
        iLast--;
    }
}


//w uporządkowanej tablicy rosnącej

int Search(int v)
{
    int i =0;
    int j = iLast;
    while (i<=j)
    {
        int k = (i+j)/2;
        if (A[k]>=v) j = k-1;
        if (A[k]<=v) i = k+1;
    }
    if(i>j+1) return j+1;
    else return -1;
}

void Insert(int v)
{
    int index = Search(v);
    if(index>-1) return;
    else
    {
        for(int i = iLast; i >= index; i++)
        {
            A[i+1]=A[i];
        }
        iLast++;
        A[index]=v;
    }
}

void Delete(int v)
{
    int index = Search(v);
    if(index==-1) return;
    else
    {
        for(int i = index; i<iLast; i++)
        {
            A[i]=A[i+1];
        }
        iLast--;
    }
}

int QSearch(int v)
{
    int l = 0;
    int r = iLast;
    int p;
    do
    {
        int k = l + int(1.0*(v-A[l])/(A[r]-A[l])*(r-l+1));
        p = int(ceil(sqrt(r-l+1.0)));
        if(A[k]<=v)
            while (k+p<=r && A[k+p]<=v)
                k=k+p;
        else
            do
                if(k-p<l) k=l;
                else k=k-p;
            while(A[k]>v);
        l=k;
        if(k+p<r) r = k+p;
    } while(p>l);
    if (A[l]==v) return l;
    else return -1;
}

int main()
{
    int A[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    cout << Search(8) << endl;
}
