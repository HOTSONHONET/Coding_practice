#include <bits/stdc++.h>

using namespace std;

#define MAX_CHARS 256

/*

Let us talk about the linear time solution now. This solution uses extra space to store the last indexes of already visited characters. The idea is to scan the string from left to right, keep track of the maximum length Non-Repeating Character Substring seen so far in res. When we traverse the string, to know the length of current window we need two indexes. 
1) Ending index ( j ) : We consider current index as ending index. 
2) Starting index ( i ) : It is same as previous window if current character was not present in the previous window. To check if the current character was present in the previous window or not, we store last index of every character in an array lasIndex[]. If lastIndex[str[j]] + 1 is more than previous start, then we updated the start index i. Else we keep same i.



*/

// s is the given string
int SubsequenceLength(string s)
{
    // Your code goes here
    int n = s.length();

    if (n == 0)
        return 0;
    int lastIndex[MAX_CHARS];
    memset(lastIndex, -1, sizeof(lastIndex));

    int i = 0, res = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, lastIndex[s[j]] + 1);
        res = max(res, j - i + 1);
        lastIndex[s[j]] = j;
    }
    return res;
}