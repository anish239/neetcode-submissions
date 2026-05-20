class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        vector<int>ans;
        for(auto s:nums){
            mp[s]++;
        }
        for(auto &[num,count]:mp){
            if(count > floor(n/3)){
                ans.push_back(num);
            }
        }
        return ans;
    }
};