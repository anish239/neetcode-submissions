class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(),strs.end());

        string &first = strs.front();
        string &back = strs.back();

        int i = 0;
        while(i<first.size() && i<back.size() && first[i] == back[i]){
            i++;
        }

        return first.substr(0,i);
    }
};