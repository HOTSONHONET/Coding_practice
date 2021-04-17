// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
   
    //code here      
    int cnt_0 = 0;
    long long int p = 1;
    for(auto i: nums){
        if (i==0){
            p*=1;
            cnt_0 ++;
        }
        else p *= i;
    }
    vector<long long int> ans;
    if (cnt_0 > 1){
        for(auto i: nums){
            ans.push_back(0);
        }
    }
    else{
        for(auto i: nums)
        {   
            
            if (i == 0){
                ans.push_back(p);
            }
            else if((i!=0) && (cnt_0 == 1)){
                ans.push_back(0);
            }
            else{
                ans.push_back(p/i);
            }
            
        }
    }

    return ans;
    
}
