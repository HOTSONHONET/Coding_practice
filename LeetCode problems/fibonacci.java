class Solution {
    public int fib(int n) {
        if(n==0) return 0;
        int[] fibNums = new int[30];
        int i = 0;
        while(i<n){
            if(i == 0 || i == 1) fibNums[i] = 1;
            else{
                fibNums[i] = fibNums[i-1] + fibNums[i-2];
            }
            i++;            
        }
        return fibNums[n-1];
    }
}