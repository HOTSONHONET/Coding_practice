// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int M = A.size(), N = B.size();
 
        // Let us create a 2D table
        // to store solutions of
        // subproblems.  C[i][j] will
        // be true if C[0..i+j-1]
        // is an interleaving of
        // A[0..i-1] and B[0..j-1].
        bool IL[M + 1][N + 1];
     
        // Initialize all values as false.
        memset(IL, 0, sizeof(IL));
     
        // C can be an interleaving of
        // A and B only of the sum
        // of lengths of A & B is equal
        // to the length of C.
        if ((M + N) != C.size())
            return false;
     
        // Process all characters of A and B
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                // two empty strings have an
                // empty string as interleaving
                if (i == 0 && j == 0)
                    IL[i][j] = true;
     
                // A is empty
                else if (i == 0) {
                    if (B[j - 1] == C[j - 1])
                        IL[i][j] = IL[i][j - 1];
                }
     
                // B is empty
                else if (j == 0) {
                    if (A[i - 1] == C[i - 1])
                        IL[i][j] = IL[i - 1][j];
                }
     
                // Current character of C matches
                // with current character of A,
                // but doesn't match with current
                // character of B
                else if (
                    A[i - 1] == C[i + j - 1]
                    && B[j - 1] != C[i + j - 1])
                    IL[i][j] = IL[i - 1][j];
     
                // Current character of C matches
                // with current character of B,
                // but doesn't match with current
                // character of A
                else if (
                    A[i - 1] != C[i + j - 1]
                    && B[j - 1] == C[i + j - 1])
                    IL[i][j] = IL[i][j - 1];
     
                // Current character of C matches
                // with that of both A and B
                else if (
                    A[i - 1] == C[i + j - 1]
                    && B[j - 1] == C[i + j - 1])
                    IL[i][j]
                        = (IL[i - 1][j]
                           || IL[i][j - 1]);
            }
        }
     
        return IL[M][N];
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends