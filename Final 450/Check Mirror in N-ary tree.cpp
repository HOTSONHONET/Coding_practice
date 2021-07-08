// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  /*
  We will use stack and queue data structure since stack follow LIFO
  that is last in first out the way and queue follow FIFO first in first out pattern,
  is the trees are mirror then the top of the stack will be equal to the front of the queue
  and if they aren't equal it means that they are not the mirror of each other.

  We will follow this approach, taking each node at a time and checking its
  connected component in stack and queue. For checking whether each subtree in
  itself is a mirror or not we will use a boolean variable flag, initially,
  the flag is true and each time we check if the top of stack and queue front 
  are equal or not, if not then simply return NO as the answer and after checking
  all nodes return true if all are valid nodes.
  
  
  */
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        bool same = true;
        stack<int> s[n+1];
        queue<int> q[n+1];
        
        for(int i = 0; i<2*e; i+=2){
            s[A[i]].push(A[i + 1]);
            q[B[i]].push(B[i + 1]);
        }
        
        for(int i = 1; i<=n; i++){
            stack<int>& ss = s[i];
            queue<int>& sq = q[i];
            
            while(!ss.empty() and !sq.empty())
            {
                if(ss.top() != sq.front()){
                    same = false;
                    break;
                } 
                
                ss.pop(); sq.pop();
            }
            
            if(!same) break;
        }
        
        return(same) ? 1 : 0;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends