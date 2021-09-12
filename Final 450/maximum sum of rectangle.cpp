// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int kadane(int* arr, int* start, int* finish, int n)
    {
        // initialize sum, maxSum and
        int sum = 0, maxSum = INT_MIN, i;
     
        // Just some initial value to check
        // for all negative values case
        *finish = -1;
     
        // local variable
        int local_start = 0;
     
        for (i = 0; i < n; ++i)
        {
            sum += arr[i];
            if (sum < 0)
            {
                sum = 0;
                local_start = i + 1;
            }
            else if (sum > maxSum)
            {
                maxSum = sum;
                *start = local_start;
                *finish = i;
            }
        }
     
        // There is at-least one
        // non-negative number
        if (*finish != -1)
            return maxSum;
     
        // Special Case: When all numbers
        // in arr[] are negative
        maxSum = arr[0];
        *start = *finish = 0;
     
        // Find the maximum element in array
        for (i = 1; i < n; i++)
        {
            if (arr[i] > maxSum)
            {
                maxSum = arr[i];
                *start = *finish = i;
            }
        }
        return maxSum;
    }
    
    int maximumSumRectangle(int ROW, int COL, vector<vector<int>> M) {
        // code here
        int maxSum = INT_MIN,
                 finalLeft,
                 finalRight,
                 finalTop,
                 finalBottom;
 
        int left, right, i;
        int temp[ROW], sum, start, finish;
     
        // Set the left column
        for (left = 0; left < COL; ++left) {
            // Initialize all elements of temp as 0
            memset(temp, 0, sizeof(temp));
     
            // Set the right column for the left
            // column set by outer loop
            for (right = left; right < COL; ++right) {
     
                // Calculate sum between current left
                // and right for every row 'i'
                for (i = 0; i < ROW; ++i)
                    temp[i] += M[i][right];
     
                // Find the maximum sum subarray in temp[].
                // The kadane() function also sets values
                // of start and finish. So 'sum' is sum of
                // rectangle between (start, left) and
                // (finish, right) which is the maximum sum
                // with boundary columns strictly as left
                // and right.
                sum = kadane(temp, &start, &finish, ROW);
     
                // Compare sum with maximum sum so far.
                // If sum is more, then update maxSum and
                // other output values
                if (sum > maxSum) {
                    maxSum = sum;
                    finalLeft = left;
                    finalRight = right;
                    finalTop = start;
                    finalBottom = finish;
                }
            }
        }

        return maxSum;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends