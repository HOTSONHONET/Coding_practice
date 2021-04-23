// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
        bool checkNum(int num, int n)
        {
            int f=5, cnt = 0, k = num;
            while(f<=k)
            {
                cnt += (int) k/f;
                f *= 5;
            }
            
            return (cnt >= n) ? true : false;
        }
    
        int findNum(int n)
        {
        //complete the function here
            int low = 0, high = 5*n;
            while(low<high)
            {   
                int mid = low + (high - low)/2;
                if(checkNum(mid, n)) high = mid;
                else low = mid + 1;
            }
            
            return low;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends