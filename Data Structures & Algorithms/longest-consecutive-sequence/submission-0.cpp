class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int best = 0;

        for(auto m : s){
            if(s.count(m-1)) continue;

            int curr = 1;
            while (s.count(m+curr)) curr++;
            best = max(best,curr);
        }
        return best;
    }
};
