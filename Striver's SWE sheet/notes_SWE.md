# Striver's SWE cheat sheet [💻](https://docs.google.com/document/d/1SM92efk8oDl8nyVw8NHPnbGexTS9W-1gmTEYfEurLWQ/edit)

## Calender 📅

| Tuesday      | Wednesday | Thursday      | Friday | Saturday      | Sunday      | Monday      |
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| [1](#day-1)| [2](#day-2)| [3](#day-3)| [4](#day-4)| [5](#day-5)| [6](#day-6)| [7](#day-7)      
| [8](#day-8)| [9](#day-9)| [10](#day-10)| [11](#day-11)| [12](#day-12)| [13](#day-13)| [14](#day-14)      
| [15](#day-15)| [16](#day-16)| [17](#day-17)| [18](#day-18)| [19](#day-19)| [20](#day-20)| [21](#day-21)      
| [22](#day-22)| [23](#day-23)| [24](#day-24)| [25](#day-25)| [26](#day-26)| [27](#day-27)| [28](#day-28)      
| [29](#day-29)| [30](#day-30)  


## Revision 👨🏼‍🎓🐱‍🏍

## [Day 1](#calender)

* Sort an array of 0’s 1’s 2’s without using extra space or sorting algo 

```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red, white, blue;
        red = white = blue = 0;
        
        for(auto val : nums)
        {
            if(val == 0) red++;
            else if(val == 1) white++;
            else blue++;
        }
        
        // cout<<red<<" "<<white<<" "<<blue<<endl;
        int i = 0;
        while(red--){
            nums[i] = 0;
            i++;
        }
        while(white--)
        {   
            nums[i] = 1;
            i++; 
        }
        while(blue--){
            nums[i] = 2;
            i++; 
        }
        
        // cout<<red<<" "<<white<<" "<<blue<<endl;

    }
};
```

* Repeat and Missing Number 
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long sum = accumulate(nums.begin(), nums.end(), 0);
        return (n*(n+1)/2) - sum;
        
        
    }
};

```
* Merge two sorted Arrays without extra space
```
/*

1. Gap algorithm; T(n) = O(N+M) x log(N+M); S(N) = O(1)
Pseudo code
- insert all elements in one array lets say v1
- take s = M + N, add keep on swapping v1[i + ceil(s/2)] and v1[i] for i : 0 to M+N
- now updated s = ceil(s/2) and do the above again until s > 0

*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i<n; i++) 
            nums1[i+m] = nums2[i];

        int s = m + n;
        int tmp = ceil((double)s/2);
        while(tmp)
        {   
            int i = 0;
            while(i + tmp < s)
            {
                if(nums1[i] > nums1[i + tmp]) swap(nums1[i], nums1[i+tmp]);
                i++;
            }
            if(tmp == 1) break;
            tmp = ceil((double)tmp/2);
        }
        
    }
};

/*
2. T(n) = O(M+N), S(N) = O(N+M)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> v(m + n);
        int i = 0, j = 0, k = 0;
        while(i<m and j<n)
        {   
            v[k++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
        }
        
        while(i<m) v[k++] = nums1[i++];
        while(j<n) v[k++] = nums2[j++];
        nums1 = v;
        return;
            
    }
};

/*
3. Insertion method T(N) = O(N*M) S(N) = O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        if(m==0){
            nums1 = nums2;
            return;
        }
        int i = 0, j = 0;
        while(i<m)
        {
            if(nums1[i] <= nums2[j]) i++;
            else{
                swap(nums1[i], nums2[j]);
                int l = j;
                while(l+1<n)
                {    
                    if(nums2[l] > nums2[l+1]) swap(nums2[l], nums2[l+1]); 
                    l++;
                }            
            }
        }
        
        
        for(i = 0; i<n; i++) nums1[i+m] = nums2[i];
        return;
            
    }
};

```
* Kadane's Algorithm

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx, curr_sum;
        maxx = curr_sum = nums[0];
        for(int i = 1; i<nums.size(); i++)
        {
            if(curr_sum <= 0) curr_sum = 0;
            curr_sum += nums[i];
            maxx = max(maxx, curr_sum);
        }
        return maxx;
        
    }
};
```
* Merge Overlapping Intervals
```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int minn, maxx;
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        
        minn = intervals[0][0];
        maxx = intervals[0][1];
        vector<int> tmp;
        for(int i = 1; i<n; i++)
        {
            if(maxx < intervals[i][0])
            {   
                tmp = {minn, maxx};
                ans.push_back(tmp);
                minn = intervals[i][0];
                maxx = intervals[i][1];
            }
            
            else if(maxx >= intervals[i][0]) maxx = max(maxx, intervals[i][1]);
        }
        
        tmp = {minn, maxx};
        ans.push_back(tmp);
        return ans;
        
    }
};
```
* Find the duplicate in an array of N+1 integers. 
```
/* 
    Floyd's rabbit and turtle algorithm     
    T(N) = O(N), S(N) = O(1) 
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), hare = 0, turtle = 0;
        // finding the first collision point
        while(true)
        {
            hare = nums[nums[hare]];
            turtle = nums[turtle];
            
            if(nums[hare] == nums[turtle]) break;
        }
        
        
        // Now we will slow down our hare, position it to start and start travelling 
        // with the same pace as of turtle
        hare = 0;
        while(nums[hare] != nums[turtle])
        {
            turtle = nums[turtle];
            hare = nums[hare];
        }
        
        return nums[hare];
    }
};
```
## [Day 2](#calender)

* Set Matrix Zeroes
```
/*
T(N) = O(N+M), S(N) = O(1)

Idea
====
- Use the first row and col to check whether the entire row or col should become 0 or not
- First, check for all values
- After that traverse from bottom right corner and for each value check whether the top row and col for the corresponding position is 0 or not
- if 0 then make the current element as zero
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool flag = false;
        for(int i = 0; i<rows; i++)
        {
            if (matrix[i][0] == 0) flag = true;
            for(int j = 1; j<cols; j++)
                if(matrix[i][j] == 0) matrix[0][j] = matrix[i][0] = 0;
        }
        
        for(int i = rows-1; i>=0; i--)
        {   
            for(int j = cols-1; j>=1; j--)
                if(matrix[0][j] == 0 or matrix[i][0] == 0) matrix[i][j] = 0;   
            if(flag) matrix[i][0] = 0;
        }
    }  
    
};
```
* Pascal triangle
```
/* T(N) = O(N*N) S(N) = O(N*N)*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i = 2; i<=numRows; i++)
        {
            vector<int> tmp(i);
            for(int j = 0; j<i; j++)
            {   
                tmp[j] = (j == 0 || j == i-1) ? 1 : ans[i-2][j-1] + ans[i-2][j];
            }
            
            ans.push_back(tmp);
        }
        
        
        return ans;
        
    }
};
```
* Next Permutation
```
/*

T(N) = O(N), S(N) = O(1)
Idea
====
- Start traversing for the end (N-2 position) and find the first element at index i for which A[i] <= A[i+1]. The Save that i value.
- If we didn't get any element then we will simply return the reverse of the array.
- If we have a value then we will again iterate from the back to saved_i and try to find the first index for which A[saved_i] < A[j]. The saved this jth index.
- Swap A[saved_i] and A[saved_j]
- Then reverse A, from i+1 to end or (N-1)th position

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, j;
        for(i = n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1]) break;
        }
        
        if(i<0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(j=n-1; j>i; j--)
        {
            if(nums[j] > nums[i]) break;
        }
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return;
    }
};

```

* Stock Buy and Sell
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        
        int ans = 0;
        for(int i = 1; i<n; i++)
        {
            if(prices[i] > prices[i-1])
            {
                ans = max(ans, prices[i] - prices[i-1]);
                prices[i] = prices[i-1];
            }
        }
        
        return ans;
        
        
    }
};
```

* Rotate Matrix
```
/*
T(N) = O(N*N), S(N) = O(1)

Idea
====
- First rotate the matrix wrt leading diagonal 
- Then, rotate the matrix wrt vertical mid axis
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Rotation wrt leading diagonal
        for(int i = 0; i<n; i++)
            for(int j = 0; j<i; j++)
                if(i!=j) swap(matrix[i][j], matrix[j][i]);
        // Rotation wrt vertical axis
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n/2; j++)
                swap(matrix[i][j], matrix[i][n-1-j]);
        
        return;
    }
};
```

* Inversion count
```
#include <bits/stdc++.h>
using namespace std;


int merge(int arr[], int temp[], int left, int mid, int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left; j = mid; k = left; 
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		else {
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i);
		}
	}
	while (i <= mid - 1) temp[k++] = arr[i++];
	while (j <= right) temp[k++] = arr[j++];
    
	for (i = left; i <= right; i++) arr[i] = temp[i];
	return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		mid = (right + left) / 2;
        
		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

int mergeSort(int arr[], int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

int main()
{
	int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int ans = mergeSort(arr, n);
	cout << " Number of inversions are " << ans;
	return 0;
}
```

## [Day 3](#calender)

* Search in a 2D matrix 
```
/* Binary search approach*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int l = 0, r = rows*cols - 1;
        while(l<=r)
        {   
            int mid = l + (r-l)/2;
            int curr_ele = matrix[mid/cols][mid%cols];
            if(curr_ele == target) return true;
            else if(curr_ele > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
```
* Pow(x, n)
```
/* T(N) = O(log(N) */
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
	// storing it int long long because n lies between -2**31 to 2**31 - 1
	// if we are making n positive and n == -2**31 then we will get integer overflow error
        long long nn = (n<0) ? -1*n : n; 
        while(nn > 0)
        {
            if(nn&1)
            {
                nn -= 1;
                ans *= x;
            }else{
                x *= x;
                nn /= 2;                
            }            
        }
        
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }
};
```

* Majority element n/2
```
/*
T(N) = O(N), S(N) = O(N)

Idea
====
- We will use Moore's voting algorithm. Below is the implementation
- Intuition: since the required number occurs n/2 times we will always end up with the number via the following steps of the alogrithm
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0, cnt = 0;
        for(auto i: nums)
        {
            if(cnt == 0) ele = i;
            if(i == ele) cnt++;
            else cnt--;
        }
        
        return ele;
        
        
    }
};
```
* Majority element n/3
```
/*
T(N) = O(N), S(N) = O(1)

Idea
====
- We will ue Boyer Moore Algorithm which is an modification of Moore's algorithm
- Here, since we have to find element has frequency is greater then floor(N/3)
- So, we will have at max 2 elements (at max 2 => 2 is included)
- Thus the procedure is similar as above with little modification like now we will search for 2 elements instead of one
- In the end, we will again check if our answers have the appropriate frequency

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;
        for(auto i: nums)
        {   
            if(num1 == i) cnt1++;
            else if(num2 == i) cnt2++;
            
            else if(cnt2 == 0){ num2 = i; cnt2 = 1; }
            else if(cnt1 == 0){ num1 = i; cnt1 = 1; }
            
            else{ cnt1--; cnt2--; }
        }
        
        int freq = nums.size()/3;
        if(count(nums.begin(), nums.end(), num1) > freq) ans.push_back(num1);
        if(num1 != num2 and count(nums.begin(), nums.end(), num2) > freq) 
            ans.push_back(num2);
        return ans;
    }
};
```

* Unique paths
```
/*Dynamic programming approach*/
class Solution {
public:
    
    int updateAns(int m, int n, int i, int j, vector<vector<int>> &dp)
    {
        if(i>=m or j>=n) return 0;
        if((i == m-1) and (j == n-1)) return 1;
        return dp[i][j] = (dp[i][j] != -1) ? dp[i][j] : updateAns(m, n, i+1, j, dp) + updateAns(m, n, i, j+1, dp);        
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));        
        return updateAns(m, n, 0, 0, dp);
    }
};

/* 
- Most optimal approach is to use combinatrics 
- Here total number of directions we can take (m-1) for right and (n-1) for down, thus total is m + n - 2
- Formula used here is C(m+n-2, n-1) + C(m+n-2, m-1)
- Below is the away we optimally caluculate Combination

*/
class Solution {
public:

    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = m - 1;
        double res = 1;
        for(int i = 1; i<=r; i++) res *= (N - r + i)/i;
        return (int)res;
    }
};
```
* Reverse pairs
```

/* T(N) = O(N x log(N), S(N) = O(N) */
class Solution {
public:
    
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        int cnt = 0;
        int j = mid+1;
        for(int i = low; i<=mid; i++)
        {
            while(j<=high and nums[i] > 2LL * nums[j]) j++;
            cnt += (j - (mid + 1));
        }   
        
        vector<int> tmp;
        int left = low, right = mid + 1;
        while(left<=mid and right<=high)
        {
            if(nums[left]<=nums[right]) tmp.push_back(nums[left++]);
            else tmp.push_back(nums[right++]);
        }
        
        while(left<=mid) tmp.push_back(nums[left++]);
        while(right<=high) tmp.push_back(nums[right++]);
        
        for(int i = low; i<=high; i++) nums[i] = tmp[i - low];
        return cnt;
        
    }
    
    int mergeSort(vector<int> &nums, int low, int high)
    {
        if(low>=high) return 0;
        int mid = low + (high - low)/2;
        int inv = mergeSort(nums, low, mid);
        inv += mergeSort(nums, mid+1, high);
        inv += merge(nums, low, mid, high);
        return inv;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
```

## [Day 4](#calender)
* Two Sum
```
/* T(N) = O(NlogN), S(N) = O(1) */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();        
        vector<int> tmp(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int l = 0, r = n-1;
        vector<int> ans;
        while(l<=r)
        {
            int sum = nums[l] + nums[r];
            if(sum == target and l != r) break;
            else if(sum < target) l++;
            else r--;
        }
        
        int save_l;
        for(int i = 0; i<n; i++) if(tmp[i] == nums[l]){ save_l = i; ans.push_back(i); break;}
        for(int i = 0; i<n; i++) if(tmp[i] == nums[r] and save_l != i){ ans.push_back(i); break;}
        
        return ans;
        
        
    }
};
```
* 4Sum
```
/* T(N) = O(N^3), S(N) = O(1)*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 0) return ans;
        
        
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        
        for(int i = 0; i<n; i++)
        {    
            for(int j = i+1; j<n; j++)
            {   
                int l = j+1, r = n-1;
                long long two_sum1 = target - nums[i] - nums[j];
                while(l < r)
                {   
                    long long two_sum2 = nums[l] + nums[r];
                    if(two_sum2 < two_sum1) l++;
                    else if(two_sum2 > two_sum1) r--;
                    else{
                        tmp = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(tmp);
                        
                        while(l < r and nums[l] == tmp[2]) ++l;
                        while(l < r and nums[r] == tmp[3]) --r;
                    }
                }
                
                while(j + 1 < n and nums[j+1] == nums[j]) ++j;
            }
            while(i + 1 < n and nums[i+1] == nums[i]) ++i;
        }
        
        return ans;
    }
};
```
* Longest Increasing Subsequence
```
/* T(N) = O(N), S(N) = O(1) */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> finder;
        for(auto i: nums) finder.insert(i);
        int maxx = 0;
        for(auto i: nums)
        {   
            int cnt = 0;
            if(finder.find(i-1) == finder.end())
            {   
                int tmp = i;
                while(finder.find(tmp++) != finder.end()) cnt++;
                maxx = max(maxx, cnt);
            }
        }
        
        return maxx;
    }
};
```
* Largest subarray with zero sum
```
/* T(N) = O(N), S(N) = O(1) */
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int, int> finder;
        int sum = 0, ans = 0;
        for(int i = 0; i<n; i++)
        {
            sum += A[i];
            if(sum == 0) ans = i + 1;
            else{ 
                if(finder.find(sum) != finder.end()) ans = max(ans, i - finder[sum]);
                else finder[sum] = i;
            }
        }
        
        return ans;
    }
};
```
* Count number of subarrays with zero xor
```
/* T(N) = O(N) S(N) = O(1) */
int solve(vector<int> &A, int B)
{
	map<int, int> freq;
	int cnt = 0, xorr = 0;
	for(auto i: A)
	{
		xorr = xorr ^ i;
		if(xor == B) cnt++;
		if(freq.find(xorr^B) != freq.end()) cnt += freq[xorr^B];
		
		freq[xorr] += 1;
	}
	return cnt;
}
```
* Longest substring without repeat
```
/* T(N) = O(N) S(N) = O(N) */
![image](https://user-images.githubusercontent.com/56304060/135723727-e2e96cb2-083e-4a44-bece-84c8e02e117a.png)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int n = s.size(), ans = 0;
        
        vector<int> finder(256, -1); // finder is here a hashSet
        while(right < n)
        {
            if(finder[s[right]] != -1) 
                left = max(finder[s[right]] + 1, left);
            
            finder[s[right]] = right;
            ans = max(right - left + 1, ans);     
            right++;
        }
        
        return ans;
    }
};

```

## [Day 5](#calender)

* Reverse a linked list
```
/* T(N) = O(N), S(N) = O(N) */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int n = s.size(), ans = 0;
        
        vector<int> finder(256, -1); // finder is here a hashSet
        while(right < n)
        {
            if(finder[s[right]] != -1) 
                left = max(finder[s[right]] + 1, left);
            
            finder[s[right]] = right;
            ans = max(right - left + 1, ans);     
            right++;
        }
        
        return ans;
    }
};
```
* Find the middle element of the linked list
```
/* T(N) = O(N), S(N) = O(1) */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode *tmp = head;
        while(tmp != NULL)
        {
            n++;
            tmp = tmp->next;
        }
        
        
        int mid = n/2;
        tmp = head;
        while(mid--)
        {
            tmp = tmp->next;
        }
        
        return tmp;
        
    }
};
```
* Merge two sorted arrays
```
/* T(N) = O(N), S(N) = O(1) */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL and l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* curr;
        if(l1->val < l2->val){
            curr = new ListNode(l1->val);
            l1 = l1->next;
        }else{
            curr = new ListNode(l2->val);
            l2 = l2->next;
        }
        
        ListNode* to_return = curr;
        while(l1 != NULL and l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                curr->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                curr->next = new ListNode(l2->val);
                l2 = l2->next;
            }            
            curr = curr->next;
        }
        
        
        curr->next = (l1 == NULL) ? l2 : l1;
        return to_return;
        
    }
};
```
* Remove Nth node from the end of a linked list
```
/* T(N) = O(N), S(N) = O(1) */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int N) {
        ListNode* tmp = head;
        int n = 1;
        while(tmp->next){
            ++n;
            tmp = tmp->next;
        }
        
        if(n==1) return NULL;
        if(n == N)
        {
            head = head->next;
            return head;
        }
        
        cout<<"n "<<n<<endl;
        
        int i = 0;
        tmp = head;
        while(i != n - N - 1)
        {
            tmp = tmp->next;
            i++;
        }
        
        ListNode* tmp2 = tmp->next->next;
        tmp->next = NULL;
        tmp->next = tmp2;
        return head;
        
    }
};
```
* Delete a node in constant time
```
/* T(N) = O(1), S(N) = O(1) */
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;        
        node = NULL;
    }
};
```

* Add two numbers represented in linked list
```
/* T(N) = O(N), S(N) = O(1) */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;       

        ListNode* curr = new ListNode(0), *ans;
        ans = curr;
        while(l1 != NULL and l2 != NULL)
        {   
            sum = l1->val + l2->val + carry;
            carry = sum/10; sum %= 10;
            curr->next = new ListNode(sum);
            l1 = l1->next; l2 = l2->next; 
            curr = curr->next;
        }
        
        if(carry>0 or l1!=NULL or l2!= NULL){
            ListNode* tmp = ans;
            while(tmp->next != NULL) tmp = tmp->next;
            
            if(l1 == NULL)
            {
                while(l2 != NULL)
                {   
                    sum = l2->val + carry;
                    carry = sum/10; sum %= 10;
                    tmp->next = new ListNode(sum);
                    tmp = tmp->next;
                    l2 = l2->next;
                }
            }
            else{
                while(l1 != NULL)
                {   
                    sum = l1->val + carry;
                    carry = sum/10; sum %= 10;
                    tmp->next = new ListNode(sum);
                    tmp = tmp->next;
                    l1 = l1->next;
                }
            }
            
            if(carry > 0) tmp->next = new ListNode(carry);
            
        }
        
        return ans->next;
        
    }
};
```

## [Day 6](#calender)
* Intersection point in a linkedlist
```
"""
T(N) = O(N), S(N) = O(1)
 
Definition for singly-linked list.
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None
"""
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if(headA == None or headB == None): return NULL;
        startA = headA; startB = headB;
        while(startA != startB):        
            startA = headB if (startA == None) else startA.next
            startB = headA if (startB == None) else startB.next
             
        return startA
        
	
/* T(N) = O(N), S(1) */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* startA = headA, *startB = headB;
        while(startA != startB)
        {   
            startA = (startA == NULL) ? headB : startA->next;
            startB = (startB == NULL) ? headA : startB->next;
        }
        
        return startA;
    }
};
        
```

* Linked List Cycle
```
/* T(N) = O(N), S(N) = O(1) */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* hare, *turtle;
        hare = turtle = head;
        
        while(true)
        {
            if(hare->next == NULL or turtle == NULL or hare->next->next == NULL) 
                return false;
            hare = hare->next->next;
            turtle = turtle->next; 
            
            if(hare == turtle) return true;          
                      
        }

    }
};
```
* Reverse a LinkedList in groups of size k. 
```
/* T(N) = O(N), S(N) = O(1) */
/*
Idea:
====
- The idea is to reverse k-1 connections for every group
- Use a dummy node for prev node
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || k == 1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr, *next, *prev;
        curr = next = prev = dummy;
        
        int n = 0;
        while(curr->next != NULL)
        {
            n++;
            curr = curr->next;
        }
        
        while(n >= k)
        {
            curr = prev->next;
            next = curr->next;
                
            for(int i = 1; i<k; i++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;               
            }
            
            prev = curr;
            n -= k;        
        }
        
        return dummy->next;
        
        
    }
};
```
* Palindromic Linked list
```
/* T(N) = O(N), S(N) = O(1) */

/*
Idea
====
- Use Flyod's rabbit and turtle algoithm to place the turtle at a that node whose next node is the ending of the 2nd half the palindrome
- The reverse the 2nd half
- Move the rabbit to the head node or Use the head itself and check it with the turtle whether the LL is a palindrome or not
*/
class Solution {
public:
    ListNode* reverse(ListNode* tmp)
    {
        ListNode* curr = NULL;
        while(tmp)
        {
            ListNode* next = tmp->next;
            tmp->next = curr;
            curr = tmp;
            tmp = next;            
        }
        
        return curr;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode *turtle, *rabbit;
        turtle = rabbit =  head;
        
        while(rabbit->next != NULL and rabbit->next->next != NULL)
        {
            turtle = turtle->next;
            rabbit = rabbit->next->next;
        }
        
        
        turtle->next = reverse(turtle->next);
        turtle = turtle->next;
        
        while(turtle != NULL)
        {
            if(turtle->val != head->val) return false;
            turtle = turtle->next;
            head = head->next;
        }
        
        return true;        
        
    }
};
```
* Find the starting node of the cycle in a LinkedList
![image](https://user-images.githubusercontent.com/56304060/135771645-5b604c0d-8b4e-4ded-a6c5-82d2ea0b098c.png)
```
/* T(N) = O(N), S(N) = O(1) */
/*
Idea
====
- Use Flyod's turtle and rabbit algorithm to check whether the LL contains a loop
- Stop at collision point and place the rabbit to head node
- Now start moving rabbit and turtle one step at a time, the point where they collide will be our ans
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode* turtle, *rabbit;
        turtle =  rabbit = head;
        
        while(rabbit->next != NULL and rabbit->next->next != NULL)
        {   
            turtle = turtle->next;
            rabbit = rabbit->next->next;
            if(rabbit == turtle) 
            {
                rabbit = head;
                while(rabbit != turtle)
                {
                    rabbit = rabbit->next;
                    turtle = turtle->next;
                }

                return turtle;
            }           
        }
        
        return NULL;
    }
};

```
* Rotate a LinkedList
```
/* T(N) = O(N), S(N) = O(1) */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        int cnt = 1;
        ListNode* curr = head;
        while(curr->next != NULL and ++cnt) curr = curr->next;

        curr->next = head;
        k = cnt - (k % cnt);        
        while(k--) curr = curr->next;

        head = curr->next;
        curr->next = NULL;
        
        return head;
        
    }
};
```
* Flatten LinkedList
```
T(N) = O(N), S(N) = O(1)
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/   
    
Node* merge(Node* a, Node* b)
{

    if (a == NULL)
        return b;

    if (b == NULL)
        return a;
 

    Node* result;
 
    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
 
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}

Node* flatten(Node *root)
{
   // Your code here
    if (root == NULL || root->next == NULL) return root;


    root->next = flatten(root->next);

    root = merge(root, root->next);

    return root;
 
```

## [Day 7](#calender)

* Clone a linkedList
<table>
  <tr align="center">
    <td>Make copies of each node adjacent to them</td>
    <td>Assign the random pointers</td>
    <td>Get the deep copy and retrive the original</td>
    <td>T(N) and S(N)</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/56304060/135890289-929ab59b-a761-4399-88d3-96efb4262fca.png" width=500 height=200></td>
    <td><img src="https://user-images.githubusercontent.com/56304060/135890106-dc853c27-fc46-4cab-b2dd-b3ae0eae7dc3.png" width=500 height=200></td>
    <td><img src="https://user-images.githubusercontent.com/56304060/135889965-4a455c06-b222-418d-8f12-05c1282676e5.png" width=500 height=200></td>
    <td><img src="https://user-images.githubusercontent.com/56304060/135889819-2f74b3f2-2ef4-4759-aa21-d7dd9b7d0434.png" width=500 height=200></td>
  </tr>
 </table>

```

```
* 3SUM
```
/* T(N) = O(N^2), S(N) = O(1) */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<n-2; i++)
        {    
            if(i == 0 || (i>0 and nums[i] != nums[i-1]))
            {   
                int l = i + 1, r = n-1;
                int target = 0 - nums[i];
                while(l < r)
                {   
                    int sum = nums[l] + nums[r];
                    if(sum == target)
                    {
                        vector<int> tmp = {nums[i], nums[l], nums[r]};
                        ans.push_back(tmp);
                        
                        while(l<r and nums[l] == nums[l+1]) l++;
                        while(l<r and nums[r] == nums[r-1]) r--;
                        
                        l++; r--;
                    }
                    else if(sum < target) l++;
                    else r--;
                }
            }
        }
        
        return ans;
    }
};
```
* Tapping rain water
```
/* T(N) = O(N), S(N) = O(N) */
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        
        int left[n], right[n];        
        left[0] = height[0]; right[n-1] = height[n-1];
        
        for(int i = 1; i<n; i++)        
            left[i] = max(left[i-1], height[i]);

        for(int i = n-2; i>=0; i--)          
            right[i] = max(right[i+1], height[i]);

        int total_water_content = 0;
        for(int i = 0; i<n; i++)
            total_water_content += min(left[i], right[i]) - height[i];

        return total_water_content;
    }
};
```

* Remove duplicates from a sorted array
```
/* T(N) = O(N), S(N) = O(1) */
class Solution {
public:
    
    int MAX = 1000;
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        
        int ptr = nums[0];        
        for(int i = 1; i<n; i++) 
        {
            if(nums[i] == ptr) nums[i] = MAX;
            else ptr = nums[i];
        }
        
        sort(nums.begin(), nums.end());        
        int ans = 0, i = 0;
        while(i<n)
        {
            if(nums[i++] != MAX) ans++;
        }
        return ans;
        
    }
};
```
* Max consecutive ones
```
/* T(N) = O(N), S(N) = O(1) */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxx = 0, sum = 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                maxx = max(sum, maxx);
                sum = 0;
                
            }else sum++;
        }
        
        return max(maxx, sum);
    }
};
```
## [Day 8](#calender)
```
<-Nothing->
```

## [Day 9](#calender)
```
<-Nothing->
```

## [Day 10](#calender)
```
<-Nothing->
```

## [Day 11](#calender)
```
<-Nothing->
```

## [Day 12](#calender)
```
<-Nothing->
```

## [Day 13](#calender)
```
<-Nothing->
```

## [Day 14](#calender)
```
<-Nothing->
```

## [Day 15](#calender)
```
<-Nothing->
```

## [Day 16](#calender)
```
<-Nothing->
```

## [Day 17](#calender)
```
<-Nothing->
```

## [Day 18](#calender)
```
<-Nothing->
```

## [Day 19](#calender)
```
<-Nothing->
```

## [Day 20](#calender)
```
<-Nothing->
```

## [Day 21](#calender)
```
<-Nothing->
```

## [Day 22](#calender)
```
<-Nothing->
```

## [Day 23](#calender)
```
<-Nothing->
```

## [Day 24](#calender)
```
<-Nothing->
```

## [Day 25](#calender)
```
<-Nothing->
```

## [Day 26](#calender)
```
<-Nothing->
```

## [Day 27](#calender)
```
<-Nothing->
```

## [Day 28](#calender)
```
<-Nothing->
```

## [Day 29](#calender)
```
<-Nothing->
```

## [Day 30](#calender)
```
<-Nothing->
```
