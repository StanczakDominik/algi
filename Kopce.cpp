void UpHeap(int i)
{
  A[0] = MaxInt;
  int v = A[i];
  while(A[i/2] < v)
  {
    A[i] = A[i/2];
    i = i/2;
  }
  A[i]=v;
}

void DownHeap(int i, int n)
{
  int k=2*i;
  int v = A[i];
  while (k <=n)
  {
    if(k+1<=n)
    {
      if (A[k+1]>A[k])
        k++;
    }
    if(A[k]>v)
    {
      A[i]=A[k];
      i=k;
      k=2*i;
    }
    else
      break;
  }
  A[i] = v;
}

void DownHeap(int i, int n)
{
  int k = 2*i;
  if(k>n) return;
  if(A[i] > A[k] and k + 1 > n) return;
  if(A[i] > max (A[k, A[k+1])) return;
  //?????????
}

void NRDownHeap(int i, int n)
{
  int k = 2*i;
  while(true)
  {
    if(k>n) break;
    if(k+1<=n and A[k+1] > A[k])
    {
      k++;
    }
    if(A[i] >= A[k]) break;
    A[i] <-> A[k];
    i=k;
  }
}
