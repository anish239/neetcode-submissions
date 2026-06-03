class Solution {
    private:
    void solve(int index, int &total_sum, int currXor, vector<int>&nums){
        total_sum += currXor;

        for(int i = index; i<nums.size(); i++){
            currXor ^= nums[i];
            solve(i+1,total_sum,currXor,nums);
            currXor ^= nums[i];
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int total_sum = 0;
        solve(0,total_sum,0,nums);
        return total_sum;
    }
};