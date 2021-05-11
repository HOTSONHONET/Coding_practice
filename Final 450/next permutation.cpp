class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i = nums.size()-1; i>0 && nums[i] <= nums[i-1]; i--);
        if(i > 0){
            int j;
            for(j = nums.size()-1; j>=i && nums[j] <= nums[i-1]; j--);
            swap(nums[i-1], nums[j]);
        }
        
        reverse(nums.begin()+i, nums.end());
        
    }
};