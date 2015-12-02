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
