// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        int pf = 0;
        vector<int> cache;
        int i = 0;
        while(i < N)
        {   
            int page = pages[i++];
            
            auto find_res = find(cache.begin(), cache.end(), page);
            
            if(find_res == cache.end())
            {       
                if (cache.size() == C){cache.erase(cache.begin());}
                pf++;
            }
            
            else cache.erase(find_res);

            cache.push_back(page);

        }
        
        
        return pf;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends