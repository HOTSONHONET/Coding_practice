// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 

int bS(vector<int> vec, int l, int r, int k){
    int mid;
    while(l<=r){
        mid = (l+r)/2;
        if (vec[mid] == k) return mid;
        if (vec[mid]>k) r = mid -1;
        else l = mid + 1;
    }
    return -1;
}


int Search(vector<int> vec, int k) {
    //code here
    int n = vec.size();
    int pivot = n-1;
    for(int i=1; i<n-1; i++){
        if(vec[i]<vec[i+1] && vec[i-1]>vec[i]) pivot = i;
    }
    // cout<<"PIVOT: "<<pivot<<endl;
    int left_half_search = bS(vec, 0, pivot-1, k);
    int right_half_search = bS(vec, pivot, n-1, k);
    // cout<<"left_half_search: "<<left_half_search<<endl;
    // cout<<"right_half_search: "<<right_half_search<<endl;
    if (left_half_search >= 0) return left_half_search;
    if (right_half_search >= 0) return right_half_search;
    else return -1;
     
}