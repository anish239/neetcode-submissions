class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, count] : freq)
            buckets[count].push_back(num);

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 1 && (int)result.size() < k; i--)
            for (int num : buckets[i])
                result.push_back(num);

    return result;
    }
};
