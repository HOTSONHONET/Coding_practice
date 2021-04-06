#include<bits/stdc++.h>

using namespace std;


int solve(vector<int> arr, int n, int x, int k){
    int i = 0;
    while(i<n){
        if(arr[i] == x) return 1;

        i = i + max(1, (arr[i] - x)/k);
    }

    return -1;
}


int main(){

    int tc;
    cin>>tc;

    while(tc--){
        int n, x, k;
        cin>>n>>x>>k;

        vector<int> arr;
        while(n--){
            int tmp;
            cin>>tmp;
            arr.push_back(tmp);
        }

        cout<<solve(arr, n, x, k)<<endl;

    }

    return 0;
}