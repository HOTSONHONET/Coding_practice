// 1) Sort all jobs in decreasing order of profit. 
// 2) Iterate on jobs in decreasing order of profit.For each job , do the following : 
// a)Find a time slot i, such that slot is empty and i < deadline and i is greatest.Put the job in 
// this slot and mark this slot filled. 
// b)If no such i exists, then ignore the job. 

// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 

#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends

// Prints minimum number of platforms reqquired 
bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

int min(int a, int b){
    if(a<b) return a;
    return b;
}


pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    sort(arr, arr+n, cmp);
    
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    
    int max_profit = 0;
    int jobs = 0;
    
    for(int i=0; i<n; i++){
        for(int j = min(n, arr[i].dead)-1; j>=0; j--){
            if(visited[j] == false){
                visited[j] = true;
                jobs++;
                max_profit += arr[i].profit;
                break;
            }
        }
    }
    
    pair<int, int> res = make_pair(jobs, max_profit);
    
    return res;
    
    
} 



// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        //function call
        pair<int,int> ans = JobScheduling(arr, n);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
	return 0; 
}


  // } Driver Code Ends