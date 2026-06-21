class Solution {
    private:
    vector<string> res;
    string path;

    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int index){
        if(index == digits.size()){
            res.push_back(path);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char c : letters) {
            path.push_back(c);
            backtrack(digits, index + 1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 
        backtrack(digits,0);
        return res;
    }
};
