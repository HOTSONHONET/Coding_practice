// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        int num_digits = 1;
        
        string end = "";
        for(int i = 0; i<D; i++){
            end += "9";
        }
        int end_at = stoi(end);
        int start_from = pow(10, D-1);
        // cout<<start_from<<" "<<end_at<<endl;
        for(int i = start_from; i<=end_at; i++){
            int cur_num = i;
            int s = 0;
            while(cur_num){
                s += cur_num%10;
                cur_num/=10;
            }
            // cout<<"s : "<<s<<endl;
            if(s == S) return to_string(i);
        }

        
        return "-1";
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends