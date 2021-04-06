#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int n, int d){
    unordered_set<int> uset;
    for(int i = 0; i<n; i++){
        if(uset.find(arr[i] - d) != uset.end()) return 1;
        if(uset.find(arr[i] + d) != uset.end()) return 1;
        
        uset.insert(arr[i]);
    }

    return -1;
}


int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    int n, d;
	    cin>>n>>d;
	    
	    vector<int> arr;
	    int k = n;
	    while(k--){
	        int tmp;
	        cin>>tmp;
	        arr.push_back(tmp);
	        
	    }
	    cout<<solve(arr, n, d)<<endl;
	}
	
	
	return 0;
}