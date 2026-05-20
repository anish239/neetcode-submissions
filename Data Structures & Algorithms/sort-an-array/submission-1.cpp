class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int,int>freq;

        for(auto x:nums){
            freq[x]++;
        }

        int idx = 0;
        for(auto &[key,count]:freq){
            while(count--){
                nums[idx++] = key;
            }
        }
        return nums;
    }
};