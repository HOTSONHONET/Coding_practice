#User function Template for python3

class Solution:
    def findTwoElement(self,arr, n): 
        # code here
        
        sn = n*(n+1)/2
        sn2 = n*(n+1)*(2*n + 1)/6
        
        sm = sum(arr)
        sm2 = sum([d**2 for d in arr])
        
        aminusb = sm - sn
        aplusb = (sm2 - sn2)/aminusb
        
        b = int(0.5*(aminusb + aplusb))
        a = int(b + sn - sm)
        
        return [b, a]
        
        

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 

    tc=int(input())
    while tc > 0:
        n=int(input())
        arr=list(map(int, input().strip().split()))
        ob = Solution()
        ans=ob.findTwoElement(arr, n)
        print(str(ans[0])+" "+str(ans[1]))
        tc=tc-1
# } Driver Code Ends