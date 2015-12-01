1
2   3
4   5   6
7   8   9   10
11  12  13  14  15

i-1, j-1        i-1, j
k-i             k-i+1
                NASZ
                ELEMENT
                i+1, j              i+1, j+1
                k+i                 k+i+1


int k2ij(int k, int &i, int &j); //zwraca parę elementów, trzeba by wziąć refkę i, j
int ij2k(int &i, int &j);

int Search(int v)
{
    int k=1;
    int i = 1;
    while(k+i+1<N)
    {
        k = k+i+1;
        i++;
    }
    int j = i;

    //search wlasciwy
    while(i>0 and j>0)
    {
        if(v < A[k])
        {
            //nie ma nóżki
            if(k+i<N)
            {
                //go west
                k=k+i;
                i++;
            }
            else    //jest nóżka
            {
                //go SW
                k--;
                j--;
            }
        }
        else if(v > A[k])
        {
            //go NW
            k = k-i;
            i--;
            j--;
        }
        else return k;
    }
    //nie znalezlismy
    return -1;
}

void DownHeap(int k, int N)
{
    int v = A[k];
    int i, j = k2ij(k,i,j);     //ten syntax jest troszkę bez sensu ale co tam
    int k_current = k;
    while(k+i<N)
    {
        if(A[k+i+1]>A[k+i])
        {
            k=k+i+1;
        }
        else k=k+i;

        if(A[k]>v)
        {
            A[k_current] = A[k]
            k_current=k;
            i++;
        }
        else break;
    }
    A[k_current]=v;
}

void UpBeap(int k)
{
    int v = A[k];
    int i, j = k2ij(k, i, j);
    int k_current = k;     //k jest taki "markowany", to może nie być trafiony
    while(i>1)      //ogólnie dobry pomysł na początek, jak się zdaje. można zawsze wyjść breakiem
    {   if(j==1)
        {
            k=k-i+1;
        }
        else if (j==i)
        {
            k=k-i;
            j--;
        }
        else
        {
            if(A[k-i]>A[k-i+1])
            {
                k=k-i;
                j--;
            }
            else k=k-i+1;   //idziemy pionowo w górę i j się nie zmienia
        }

        if(A[k] > A[k_current])
        {
            A[k_current]=A[k];
            k_current=k;
            i--;
        }
        else break;
    }
    int A[k_current] = v;       //k był markowany, nie?
}
