
class Solution:
    
    def maxHeapify(self, arr, n, idx):
          
        # Find largest of node and 
        # its children 
        if idx >= n: 
            return
        l = 2 * idx + 1
        r = 2 * idx + 2
        Max = 0
        if l < n and arr[l] > arr[idx]: 
            Max = l 
        else:
            Max = idx 
        if r < n and arr[r] > arr[Max]: 
            Max = r 
      
        # Put Maximum value at root and 
        # recur for the child with the 
        # Maximum value 
        if Max != idx: 
            arr[Max], arr[idx] = arr[idx], arr[Max] 
            self.maxHeapify(arr, n, Max)
    
    
    # Builds a Max heap of given arr[0..n-1] 
    def buildMaxHeap(self, arr, n):
          
        # building the heap from first non-leaf 
        # node by calling Max heapify function 
        for i in range(int(n / 2) - 1, -1, -1):
            self.maxHeapify(arr, n, i)
            
            
    def mergeHeaps(self, a, b, n, m):
        #your code here
        merged = [0]*(n+m)
        # Copy elements of a[] and b[] one 
        # by one to merged[] 
        for i in range(n):
            merged[i] = a[i]
        for i in range(m):
            merged[n + i] = b[i]
      
        # build heap for the modified 
        # array of size n+m 
        self.buildMaxHeap(merged, n + m)
        return merged
            

#{ 
#  Driver Code Starts
#Initial Template for Python 3

def isMerged(arr1, arr2, merged):
    if (len(arr1) + len(arr2) != len(merged)):
        return False
    arr1 += arr2
    arr1.sort()
    mergedCopy = sorted(merged)
    if (arr1 != mergedCopy):
        return False
    for i in range(1, len(merged)):
        if merged[i] > merged[(i-1)//2]:
            return False

    return True

if __name__ == "__main__":
    for _ in range(int(input())):
        n, m = map(int, input().split())
        a = [int(i) for i in input().split()]
        b = [int(i) for i in input().split()]
        copyA = a[:]
        copyB = b[:]
        obj = Solution()
        merged = obj.mergeHeaps(a, b, n, m)
        flag = isMerged(copyA, copyB, merged)
        print(0 if flag == False else 1)

# } Driver Code Ends