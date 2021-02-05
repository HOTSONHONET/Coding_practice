// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here

    // Logic:
    // Using dp we will store the answer for every possible combination of #items and W
    // for stoing will be collecting the max of(curValue + value in knapSack, value in knapsack)



   int K[n+1][W+1];
   for(int i = 0; i<=n; i++){
       for(int w = 0; w<=W; w++){
           if(w == 0 || i == 0) K[i][w] = 0;
           
           else if(wt[i-1] <= w){
               K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
           }
           else{
               K[i][w] = K[i-1][w];
           }
       }
   }
   return K[n][W];
   
}





// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends