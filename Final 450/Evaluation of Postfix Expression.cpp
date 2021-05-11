// { Driver Code Starts
// C++ program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int eval(int c, int d, char op){
        int a = c, b = d;
        int ans;
        switch(op){
            case('+'):
                ans = a+b;
                break;
            
            
            case('-'):
                ans = a-b;
                break;
            
            
            case('*'):
                ans = a*b;
                break;
            
            
            default:
                ans = a/b;
        }
        return ans;
    }
    
    long evaluatePostfix(string S)
    {
        // Your code here
        stack<int> stk;
        int ans;
        int a, b;
        for(int i = 0; i<S.size(); i++){
            if((!stk.empty()) && (S[i] == '+' || S[i] == '*' || S[i] == '/' || S[i] == '-')){
                b = stk.top(); stk.pop();
                a = stk.top(); stk.pop();
                ans = eval(a, b, S[i]);
                stk.push(ans);
                // cout<<a<<S[i]<<b<<" "<<stk.top()<<endl;
            }
            else{
                // cout<<"Pushing "<<S[i]<<endl;
                stk.push(S[i] - '0');
                
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends