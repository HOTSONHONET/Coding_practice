// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    const int MAX_CHARS = 256;
    
    string findSubString(string str)
    {
        // Your code goes here   
        int n = str.length();
 
        // Count all distinct characters.
        int dist_count = 0;
        bool visited[MAX_CHARS] = { false };
        for (int i = 0; i < n; i++) {
            if (visited[str[i]] == false) {
                visited[str[i]] = true;
                dist_count++;
            }
        }
     
        // Now follow the algorithm discussed in below
        // post. We basically maintain a window of characters
        // that contains all characters of given string.
        int start = 0, start_index = -1, min_len = INT_MAX;
     
        int count = 0;
        int curr_count[MAX_CHARS] = { 0 };
        for (int j = 0; j < n; j++) {
            // Count occurrence of characters of string
            curr_count[str[j]]++;
     
            // If any distinct character matched,
            // then increment count
            if (curr_count[str[j]] == 1)
                count++;
     
            // if all the characters are matched
            if (count == dist_count) {
                // Try to minimize the window i.e., check if
                // any character is occurring more no. of times
                // than its occurrence in pattern, if yes
                // then remove it from starting and also remove
                // the useless characters.
                while (curr_count[str[start]] > 1) {
                    if (curr_count[str[start]] > 1)
                        curr_count[str[start]]--;
                    start++;
                }
     
                // Update window size
                int len_window = j - start + 1;
                if (min_len > len_window) {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }
        return str.substr(start_index, min_len);
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends