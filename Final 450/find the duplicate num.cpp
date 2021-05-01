class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> cnt;
        for(auto i: nums){
            cnt[i]++;
        }
        
        int ans;
        for(auto i: cnt){
            if (i.second > 1){
                ans = i.first;
                break;
            }
        }
        
        return ans;
    }
};