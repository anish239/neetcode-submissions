class Solution {
    private:
    void check_target(int index, vector<int>&nums, int target, vector<int>&curr, vector<vector<int>>&ans){
        int sum = accumulate(curr.begin(), curr.end(), 0);
        if(sum > target) return;
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        for(int i = index; i<nums.size(); i++){
            curr.push_back(nums[i]);
            check_target(i,nums,target,curr,ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        check_target(0,nums,target,curr,ans);
        return ans;
    }

};
