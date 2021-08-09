#User function Template for python3

from bisect import *

class Solution:
    
    #Function to find length of longest increasing subsequence.
    def longestSubsequence(self,v,n):
        
        if len(v) == 0:  # boundry case
            return 0
 
        tail = [0 for i in range(len(v) + 1)]
        length = 1  # always points empty slot in tail
     
        tail[0] = v[0]
     
        for i in range(1, len(v)):
            if v[i] > tail[length-1]:
                # v[i] extends the largest subsequence
                tail[length] = v[i]
                length += 1
     
            else:
                # v[i] will extend a subsequence and discard older subsequence
     
                # find the largest value just smaller than v[i] in tail
     
                # to find that value do binary search for the v[i] in
                # the range from begin to 0 + length
     
                # bisect function either returns index where element is found
                # or the appropriate index at which element should be placed
     
                # finally replace the existing subsequene with new end value
                tail[bisect_left(tail, v[i], 0, length-1)] = v[i]
     
        return length
       


#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        a = [ int(x) for x in input().split() ]
        ob=Solution()
        print(ob.longestSubsequence(a,n))
# } Driver Code Ends