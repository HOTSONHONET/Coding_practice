class Solution:
    # Your task is to complete this function
    # Function should return an integer
    def countPs(self,str):
        # Code here
        N = len(str) 
      
        # Create a 2D array to store the count 
        # of palindromic subsequence 
        cps = [[0 for i in range(N + 2)]for j in range(N + 2)] 
          
        # palindromic subsequence of length 1 
        for i in range(N): 
            cps[i][i] = 1
          
        # check subsequence of length L   
        # is palindrome or not 
        for L in range(2, N + 1): 
          
            for i in range(N): 
                k = L + i - 1
                if (k < N): 
                    if (str[i] == str[k]): 
                        cps[i][k] = (cps[i][k - 1] +
                                    cps[i + 1][k] + 1) 
                    else: 
                        cps[i][k] = (cps[i][k - 1] +
                                    cps[i + 1][k] -
                                    cps[i + 1][k - 1]) 
          
        # return total palindromic subsequence 
        return int(cps[0][N - 1] % (1000000000 + 7))


#{ 
#  Driver Code Starts
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        ob=Solution()
        print(ob.countPs(input().strip()))

# } Driver Code Ends