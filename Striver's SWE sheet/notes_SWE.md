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
```
<-Nothing->
```

## [Day 4](#calender)
```
<-Nothing->
```

## [Day 5](#calender)
```
<-Nothing->
```

## [Day 6](#calender)
```
<-Nothing->
```

## [Day 7](#calender)
```
<-Nothing->
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
