class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>seen;
        int n = s.size();
        int l = 0;
        int maxLen = 0;

        for(int i = 0; i<n; i++){
            while(seen.count(s[i])){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[i]);
            maxLen = max(maxLen,i-l+1);
        }
        return maxLen;
    }
};
