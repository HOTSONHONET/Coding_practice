// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

//Function to reverse the queue

void emptyQ(queue<int> &q, vector<int> &v){
    if(q.size() == 0) return;
    v.push_back(q.front());
    q.pop();
    emptyQ(q, v);
}

queue<int> rev(queue<int> q)
{
    // add code here.
    int n = q.size();
    vector<int> v;
    emptyQ(q, v);
    for(int i = n-1; i>=0; i--){
        q.push(v[i]);
    }
    
    return q;
}