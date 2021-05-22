// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string str){
        // Code Here
       int chk[26];
       int n = str.size();
       memset(chk, -1, sizeof(chk));
       
       int i, j;
       // 
       for(i = 0; i<n; i++){
           if(chk[str[i] - 'a'] == -1) chk[str[i] - 'a'] = i;
       }
       
       for(i = 0; i<n; i++){
           bool flag = false;
           for(j = 0; j<str[i] - 'a'; j++){
               if (chk[j] > chk[str[i] - 'a']){
                   flag = true;
                   break;
               }
           }
           
           if(flag) break;
       }
       
       // Checking whether we got a pair
       if(i<n){
           char c1 = str[i], c2 = char(j+'a');
           for(i = 0; i<n; i++){
               if(str[i] == c1) str[i] = c2;
               else if(str[i] == c2) str[i] = c1;
           }
       }
       
       return str;
       
       
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends