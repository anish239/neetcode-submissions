class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        unordered_map<int,int>mp;
        for(auto &num:nums){
            mp[num]++;
        }
        for(auto &[key,count]:mp){
            if(count > sz/2){
                return key;
            }
        }
        return -1;
    }
};