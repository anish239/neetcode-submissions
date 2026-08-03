class Solution {
    private:
    bool solve(int idx, vector<int>& nums, vector<int>& bucket, int target){
        if(idx == nums.size()){
            return true;
        }

        for(int i = 0; i<bucket.size(); i++){
            if(bucket[i]+nums[idx] > target){
                continue;
            }
            bucket[i] += nums[idx];

            if(solve(idx+1,nums,bucket,target)){
                return true;
            }
            bucket[i] -= nums[idx];

            if(bucket[i] == 0){
                break;
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % k){
            return false;
        }

        sort(nums.rbegin(),nums.rend());

        vector<int>bucket(k,0);
        return solve(0,nums,bucket,sum/k);
    }
};