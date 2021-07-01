// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int prior(char c)
{
    if(c=='I') return 1;
    if(c=='V') return 2;
    if(c=='X') return 3;
    if(c=='L') return 4;
    if(c=='C') return 5;
    if(c=='D') return 6;
    if(c=='M') return 7;
    
    return 0;
}

int value(char c)
{
    if(c=='I') return 1;
    if(c=='V') return 5;
    if(c=='X') return 10;
    if(c=='L') return 50;
    if(c=='C') return 100;
    if(c=='D') return 500;
    if(c=='M') return 1000;
    
    return 0;
    
}
    
int romanToDecimal(string &s) {
    int len=s.length();
    int ans=value(s[len-1]);   
    for(int i=len-2; i>=0; i--)
    {
        if(prior(s[i])>=prior(s[i+1]))
        {
            ans+=value(s[i]);
        }
        else
        {
            ans-=value(s[i]);
        }
    }
    return ans;
}