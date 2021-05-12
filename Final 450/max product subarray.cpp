#User function Template for python3
class Solution:

	# Function to find maximum
	# product subarray
	def maxProduct(self,arr, n):
		# code here
		max_ = arr[0]; min_ = arr[0]; ans = arr[0]
		for i in range(1, n):
		    
		    if(arr[i] < 0):
		        tmp = max_
		        max_ = min_
		        min_ = tmp
		    
		    max_ = max(arr[i], max_*arr[i])
		    min_ = min(arr[i], min_*arr[i])
            
            ans = max(ans, max_)
        return ans
        
            
            
            
#{ 
#  Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.maxProduct(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends