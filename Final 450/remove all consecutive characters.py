#User function Template for python3

class Solution:
    def removeConsecutiveCharacter(self, S):
        # code here
        S = list(S.rstrip())
        n = len(S)
     
        # We don't need to do anything for
        # empty or single character string.
        if (n < 2) :
            return "".join(S)
             
        # j is used to store index is result
        # string (or index of current distinct
        # character)
        j = 0
         
        # Traversing string
        for i in range(n):
             
            # If current character S[i]
            # is different from S[j]
            if (S[j] != S[i]):
                j += 1
                S[j] = S[i]
         
        # Putting string termination
        # character.
        j += 1
        S = S[:j]
        return "".join(S)

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())

    for tcs in range(T):
        s = input()
        ob = Solution()
        print(ob.removeConsecutiveCharacter(s))

# } Driver Code Ends