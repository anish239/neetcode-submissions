class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>arr;

        for(int i = 0; i<=n-k; i++){
            int maxval = nums[i];
            for(int j = i; j<i+k; j++){
                maxval = max(maxval,nums[j]);
            }
            arr.push_back(maxval);
        }
        return arr;
    }
};
