from collections import defaultdict
from bisect import bisect_right as upper_bound

def minOperations (N, A, K):
#Write your code here
    finder = defaultdict(list)
    for i in range(len(A)):
        subArray_idx = i % K
        idx = upper_bound(finder[subArray_idx], A[i])

        if idx == len(finder[subArray_idx]):
            finder[subArray_idx].append(A[i])
        else:
            finder[subArray_idx][idx] = A[i]

    cnt = 0
    for idx, subarray in finder.items():
        init_cnt = (N - 1 - idx)//K + 1 
        cnt += init_cnt - len(subarray)
    
    return cnt

T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    K = int(input())

    out_ = minOperations(N, A, K)
    print (out_)