from time import sleep

A=[0,5,4,3,2,1,15,51,41,3,9,4,5,2,6]
N=len(A)-1

def Median(x, y, z):
    if(x>y):
        y,x = x, y
    if(y>z):
        z, y = y, z
    return y

def Partition(A, l, r):
    v = A[l]
    i = l
    j = r+1
    while(i<j):
        print(l, j, v, r,A)
        while(i<=N):
            i+=1
            if(A[i]>v):
                break
        while(j>1):
            j-=1
            try:
                if(A[j]<v):
                    break
            except IndexError:
                input(j)
        if(i<j):
            A[i], A[j] = A[j], A[i]
    A[l] = A[j]
    A[j] = v
    return j

# def Partition(A, l, r):
#     # x, y, z = A[1], A[-1], A[N//2]
#     # v = Median(x,y,z)
#     v = A[N]
#     i = l-1
#     for j in range(l, r):
#         print("i: %d, j: %d, l: %d, r: %d, v: %d" %(i, j, l, r, v), A)
#         if(A[j] <= v):
#             i+=1
#             A[j], A[i] = A[i],A[j]
#     A[i+1], A[r] = A[r], A[i+1]
#     print("l: %d, r: %d, v: %d" %(l, r, v), A)
#     return i+1

def QuickSortNR(A):
    S = []
    l, r = 1, N
    S+=l, r
    while(len(S)>0):
        r, l = S.pop(), S.pop()
        j = Partition(A, l, r)
        print("l: %d, j: %d, r: %d" %(l, j, r), A, S)
        while(r>l):
            if(j-l > r-j):
                S+=l,j-1
                l = j+1
            else:
                S+=j+1,r
                r = j-1
            input()

QuickSortNR(A)
