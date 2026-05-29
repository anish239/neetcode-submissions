class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int s = 1; s <= target; s++)
            for (int num : nums)
                if (num <= s)
                    dp[s] += dp[s - num];

        return dp[target];
    }
};