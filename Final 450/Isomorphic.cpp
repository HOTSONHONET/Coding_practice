// Let us talk about the linear time solution now. This solution uses extra space to store the last indexes of already visited characters. The idea is to scan the string from left to right, keep track of the maximum length Non-Repeating Character Substring seen so far in res. When we traverse the string, to know the length of current window we need two indexes.
// 1) Ending index ( j ) : We consider current index as ending index.
// 2) Starting index ( i ) : It is same as previous window if current character was not present in the previous window. To check if the current character was present in the previous window or not, we store last index of every character in an array lasIndex[]. If lastIndex[str[j]] + 1 is more than previous start, then we updated the start index i. Else we keep same i.

// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        cout<<areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}// } Driver Code Ends

#include<bits/stdc++.h>

// This function returns true if str1 and str2 are ismorphic
// else returns false
bool areIsomorphic(string str1, string str2)
{
    
    // Your code here
    int m = str1.length(), n = str2.length();
    if(m!=n) return false;
    
    int map[MAX_CHARS];
    memset(map, -1, sizeof(map));
    
    int marked[MAX_CHARS] = {false};
    
    for(int i = 0; i<m; i++){
        if(map[str1[i]] == -1){
            if(marked[str2[i]]) return false;
            marked[str2[i]] = true;
            map[str1[i]] = str2[i]; 
        }
        else if(map[str1[i]] != str2[i]) return false;
    }
    return true;
    
    
}