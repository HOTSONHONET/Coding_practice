#include <bits/stdc++.h>
using namespace std;

// sort the array
// max_dist_possible = arr[n-1] and min_distance = 1
// perform a binary for between (1, arr[n-1])
// and keep on checking whether the mid value is feasible solution or not

// For checking the feasible value
// traverse the array and initialize a variable(pos) with the first element of the sorted array
// for each iteration check whether the distance between the current num and pos is >= mid or not
// if it is then update the pos with the current num
// also keep a element counter which will keep track of the no of elements that has distances greater than mid
// if the counter value is greater than k then it is a feasible solution

// if mid value is a feasible solution, keep looking on the right side i.e (mid + 1, arr[n-1])
// Since we want the maximum distance possible
// else check on the left side i.e (1, mid-1)

bool isFeasible(int mid, int arr[], int n, int k){
    int pos = arr[0], ele = 1;
    for(int i = 1; i<n; i++){
        if((arr[i] - pos) >= mid){
            pos = arr[i];
            ele++;
        }
        if(ele == k) return true;
    }
    return false;
    
}


int solve(int arr[], int n, int k){
    sort(arr, arr+n);
    
    if(n<k) return -1;
    
    // int max_diff = arr[n-1] - arr[0];
    int ans = -1;
    int l = 1, r = arr[n-1];
    while(l<r){
        int mid = l + (r-l)/2;
        // cout<<"mid : "<<mid<<endl;
        if(isFeasible(mid, arr, n, k)){
            ans = max(ans, mid);
            // cout<<"ans : "<<ans<<endl;
            l = mid + 1;
        }
        else r = mid;
    }
    return ans;
}


int main() {
	int t;
	cin>>t;
	for(int i = 0; i<t; i++){
	    int n, k;
	    cin>>n>>k;
	    int arr[n];
	    for(int j = 0; j<n; j++){
	        cin>>arr[j];
	    }
        cout<<solve(arr, n, k)<<endl;
	}
	return 0;
}