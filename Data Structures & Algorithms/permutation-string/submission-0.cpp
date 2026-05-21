class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> s1Count, windowCount;
        for (char c : s1) s1Count[c]++;

        int left = 0;

        for (int right = 0; right < s2.size(); right++) {
            windowCount[s2[right]]++;
            if (right - left + 1 > s1.size()) {
                windowCount[s2[left]]--;
                if (windowCount[s2[left]] == 0)
                    windowCount.erase(s2[left]);
                left++;
            }
            if (windowCount == s1Count) return true;
        }

        return false;
    }
};
