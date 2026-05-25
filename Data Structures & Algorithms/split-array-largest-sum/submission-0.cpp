class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        int res = r;

        while(l<=r){
            int curr = 0,splits = 1;
            int mid = l + (r - l)/2;

            for(int i = 0; i<nums.size(); i++){
                if(curr + nums[i] > mid){
                    splits++;
                    curr = 0;
                }
                curr += nums[i];
            }

            if(splits <= k){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return res;
    }
};