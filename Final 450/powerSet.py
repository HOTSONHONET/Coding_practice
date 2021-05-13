#User function Template for python3

class Solution:
	def AllPossibleStrings(self, s):
		# Code here
		n = len(s)
		pn = 2**n
		ans = []
		for i in range(pn):
		    res = ""
		    for j in range(n):
		        if(i & (1<<j) > 0):
		            res += s[j]
            ans.append(res)
        
        # to remove the "" / empty string, I have used ans[1:]
        return sorted(ans[1:])

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		s = input()
		ob = Solution();
		ans = ob.AllPossibleStrings(s)
		for i in ans:
			print(i, end = " ");
		print()
# } Driver Code Ends