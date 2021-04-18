#include <bits/stdc++.h>

using namespace std;

int bs(vector<int> s, int qtmp){
    int n = s.size();
    int r = n - 1;
    int l = 0;
    int mid;
    while(l<=r){
        mid = l + (r-l)/2;
        if((s[mid]<=qtmp) && (mid==n-1 || s[mid+1] > qtmp)){
            return mid;
        }
        else if(s[mid] > qtmp){
            r = mid-1;
        }
        else l = mid + 1;
    }

    return mid;
    
}


pair<int, int> solve(vector<int> s, int q)
{
    int idx = bs(s, q);
    int a = idx + 1;
    int b = 0;
    for(int i = 0; i<=idx; i++){
        b+=s[i];
    }

    return make_pair(a, b);
}



int main(){
    int n;
    cin>>n;
    vector<int> s;
    while(n--){
        int tmp;
        cin>>tmp;
        s.push_back(tmp);
    }

    sort(s.begin(), s.end());

    int q;
    cin>>q;
    while(q--){
        int qtmp, a, b;
        cin>>qtmp;
        pair<int, int> p = solve(s, qtmp);
        cout<<p.first<<" "<<p.second<<endl;
    }

    return 0;
}