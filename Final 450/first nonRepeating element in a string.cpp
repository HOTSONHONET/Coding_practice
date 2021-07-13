// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
		    // Code here
		    queue<char> q;
		    string ans = "";
            int charCount[26] = { 0 };
         
            // traverse whole stream
            for (int i = 0; str[i]; i++) {
         
                // push each character in queue
                q.push(str[i]);
         
                // increment the frequency count
                charCount[str[i] - 'a']++;
         
                // check for the non pepeating character
                while (!q.empty()) {
                    if (charCount[q.front() - 'a'] > 1)
                        q.pop();
                    else {
                        ans += q.front();
                        break;
                    }
                }
         
                if (q.empty())
                    ans += '#';
            }
            
            return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends