#User function Template for python3
from collections import defaultdict

def Anagrams(words,n):
    '''
    words: list of word
    n:      no of words
    return : list of group of anagram {list will be sorted in driver code (not word in grp)}
    '''
    grps = defaultdict(list)
    for w in words:
        grps[''.join(sorted(w))].append(w)
    
    ans = []
    for v in grps.values():
        ans.append(v)
        
    return ans
        
        
        
        
        
        
        
        
        
    #{ 
#  Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ =='__main__':
    t= int(input())
    for tcs in range(t):
        n= int(input())
        words=input().split()
        
        ans=Anagrams(words,n)
        
        for grp in sorted(ans):
            for word in grp:
                print(word,end=' ')
            print()

# } Driver Code Ends