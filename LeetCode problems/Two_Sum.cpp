class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_set<int> uset;
        int n = nums.size();
        int req_num;
        for(int i = 0; i<n; i++){
            if(uset.find(target-nums[i]) != uset.end()){
                ans.push_back(i);
                req_num = target - nums[i];
                cout<<req_num<<endl;
            }
            uset.insert(nums[i]);
        }
        
        for(int i = 0; i<n; i++){
            if(nums[i]==req_num){
                ans.push_back(i);
                break;
            }
        }
        
        return ans;
    }
};