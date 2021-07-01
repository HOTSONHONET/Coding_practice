// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> small, big;
    
    void insertHeap(int &x)
    {   
        small.push(x);
        big.push(-small.top());
        small.pop();
        if(small.size() < big.size()){
            small.push(-big.top());
            big.pop();
        }
        
    }
    

    //Function to return Median.
    double getMedian()
    {
        return (small.size() > big.size()) ? small.top() : (small.top() - big.top())/2;
           
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends