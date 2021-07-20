// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    unordered_map<string, vector<string>> mp;
    unordered_set<string> word_dict;
    
    vector<string> combine(vector<string> prev, string word)
    {
        for(int i=0; i<prev.size(); ++i)
        {
            prev[i] += " " + word;
        }
        
        return prev;
    }
    
    
    vector<string> wordBreakUtil(string s)
    {
        if(mp.find(s) != mp.end())
        {
            return mp[s];
        }
        
        vector<string> res;
        if(word_dict.find(s) != word_dict.end()) res.push_back(s);
        
        for(int i = 0; i<s.size(); ++i)
        {
            string word = s.substr(i);
            if(word_dict.find(word) != word_dict.end())
            {
                string rem = s.substr(0, i);
                vector<string> prev = combine(wordBreakUtil(rem), word);
                
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        
        mp[s] = res;
        return res;
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {   
       mp.clear();
       word_dict.clear();
       word_dict.insert(dict.begin(), dict.end());
       return wordBreakUtil(s);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends