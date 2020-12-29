class Solution {
public:
    int arr[50];
    int climbStairs(int n) {

        if(n<=1) return arr[1]=1;
        if(n==2) return arr[2]=2;
        if(arr[n]!=0) return arr[n];
        
        return arr[n]=climbStairs(n-2)+climbStairs(n-1);
    }
};