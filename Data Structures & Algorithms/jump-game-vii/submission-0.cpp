class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n-1] == '1') return false;

        vector<bool> reachable(n, false);
        vector<int> prefix(n, 0);
        
        reachable[0] = true;
        prefix[0] = 1;

        for (int j = 1; j < n; j++) {
            if (s[j] == '0') {
                int lo = j - maxJump;
                int hi = j - minJump;

                if (hi >= 0) {
                    int windowSum = prefix[hi] - (lo > 0 ? prefix[lo - 1] : 0);
                    if (windowSum > 0) reachable[j] = true;
                }
            }
            prefix[j] = prefix[j-1] + (reachable[j] ? 1 : 0);
        }

        return reachable[n-1]; 
    }
};