// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies, candies + N);
        int min = candies[0], max = candies[N-1];
        
        vector<int> ans;
        int candies_left = (N-1 < K) ? 0: N-1-K;
        if(candies_left == 0){
            ans.push_back(min);
            ans.push_back(max);
            
            return ans;
        }
        
        //finding minimum amount
        int i = 1;
        int for_min = candies_left;
        while(for_min > 0){
            min += candies[i];
            for_min -= (K+1);
            i++;
            
        }
        ans.push_back(min);
        
        int j = N-2;
        while(candies_left > 0){
            max += candies[j];
            candies_left -= (K+1);
            j--;
            
        }
        ans.push_back(max);
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends