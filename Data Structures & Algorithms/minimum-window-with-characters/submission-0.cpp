class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> need, have;
        for (char c : t) need[c]++;

        int formed = 0;
        int total = need.size();
        int L = 0;
        int bestLen = INT_MAX, bestL = 0;

        for (int R = 0; R < s.size(); R++) {
            char c = s[R];
            have[c]++;
            if (need.count(c) && have[c] == need[c])
                formed++;

            while (formed == total) {
                if (R - L + 1 < bestLen) {
                    bestLen = R - L + 1;
                    bestL = L;
                }
                char lc = s[L];
                have[lc]--;
                if (need.count(lc) && have[lc] < need[lc])
                    formed--;
                L++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};
