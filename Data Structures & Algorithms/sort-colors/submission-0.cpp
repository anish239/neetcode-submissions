class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int>freq;

        for(auto x:nums){
            freq[x]++;
        }
        int idx = 0;
        for(auto &[val,cnt]:freq){
            while(cnt--){
                nums[idx++] = val;
            }
        }
    }
};