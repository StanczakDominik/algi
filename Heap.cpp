//int N = liczba elementów w tablicy;
//A[N]
//A[0] - wartownik
//maksymalny element w i=1

void UpHeap(int i)
{    //zakladam ze A[0] jest przeogromny
    int v = A[i];
    while(A[i/2] < v)
    {
        A[i]=A[i/2];
        i=i/2;
    }

    A[i] = v;
}

void DownHeap(int i, int N)
{   //1 4 6
    //zakladam ze A[0] jest wartownikiem
    int v = A[i];
    int k = 2*i;
    while(k+1<N)
    {
        if(A[k+1]>A[k]) k++;

        if(A[k]>v)      //na przykład 6 > 1
        {
            A[i]=A[k];
            i=k;
            k=2*i;
        }
        else break;
    }
    A[i]=v;
}


//Metody kolejki priorytetowej
//int hl //liczba ukopcowanych elementów
void Insert(int v)
{
    hl++;
    A[hl]=v;
    UpHeap(hl);
}

int Max()
{
    return A[1];
}

int DeleteMax()
{
    int Max = A[1];
    A[1]=A[hl];
    hl--;
    DownHeap(1);
    return Max;
}

void CreateHeapTopDown()
{
    hl = 1;
    for(int i=2; i<n; i++)
    {
        Insert(A[i]);
    }
}

void CreateHeapBottomUp()
{
    hl = n; //dlaczego? po prostu jako wyjście?
    for(int i=n/2; i>0; i--)
    {   //mozemy zacząć od połowy kopca (na początku ostatniego rzędu)
        //i nie przejmować się resztą ponieważ tak naprawdę wystarczy żeby
        // w trójce 1 6 4 puścić downheap i zrobić 6 1 4 i to załatwia całą
        // część tego rzędu. Ta notatka jest bez sensu ale chwytam ocb
        DownHeap(i,N);
    }
}
