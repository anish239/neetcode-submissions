class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();

        auto expandAroundCentre = [&](string &s,int l,int r){
            while(l>=0 && r < s.size() && s[l] == s[r]){
                cnt++;
                l--;
                r++;
            }
        };

        for(int i = 0; i<n; i++){
            expandAroundCentre(s,i,i);
            expandAroundCentre(s,i,i+1);
        }
        return cnt;
    }
};
