class Solution {
public:
    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int index, int target) {
        if (index == matchsticks.size())
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index];
                if (backtrack(matchsticks, sides, index + 1, target))
                    return true;
                sides[i] -= matchsticks[index];
            }
            if (sides[i] == 0) break;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int x : matchsticks) sum += x;
        if (sum % 4 != 0) return false;

        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sides(4, 0);
        return backtrack(matchsticks, sides, 0, sum / 4);
    }
};