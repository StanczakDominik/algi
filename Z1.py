A = [40, 5, 8, 9, 13, 8, 10]
N=len(A)

def Downheap(i, N, A):
    k = 2*i+1
    v = A[i]
    while(k<N):
        if (A[k+1]<A[k]):
            k+=1
        if (A[k] < v)
        
