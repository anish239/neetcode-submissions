class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int pre2 = 1;
        int pre1 = s[0] != '0';

        for(int i = 2; i<=n; i++){
            int curr = 0;
            int oneDigit = stoi(s.substr(i-1,1));
            int twoDigit = stoi(s.substr(i-2,2));

            if(oneDigit >= 1) curr += pre1;
            if(twoDigit >= 10 && twoDigit <= 26) curr += pre2;

            pre2 = pre1;
            pre1 = curr; 
        }
        return pre1;
    }
};
