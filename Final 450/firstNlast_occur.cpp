#include <bits/stdc++.h>

using namespace std;

int first_occur(vector<int> arr, int n, int x){
    int l = 0, r = n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] == x && (mid == 0 || arr[mid-1]!=x)){
            return mid;
        }
        else if(arr[mid-1] >= x){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

int last_occur(vector<int> arr, int n, int x){
    int l = 0, r = n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] == x && (mid == n-1 || arr[mid+1]!=x)){
            return mid;
        }
        else if(arr[mid+1] <= x){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}


int main(){
    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        int n, x;
        cin>>n>>x;
        vector<int> arr;
        for(int j  = 0; j<n; j++){
            int tmp;
            cin>>tmp;
            arr.push_back(tmp);
        }
        
        int fo = first_occur(arr, n, x);
        int lo = last_occur(arr, n, x);
        if(fo == -1 || lo == -1){
            cout<<-1<<endl;
        }
        else cout<<first_occur(arr, n, x)<<" "<<last_occur(arr, n, x)<<endl;
    }
    
    
}