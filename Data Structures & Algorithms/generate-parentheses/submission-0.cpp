class Solution {
    private:
    void solve(string curr, int open, int close, int n, vector<string>&res){
        if(open == n && close == n){
            res.push_back(curr);
            return;
        }
        if(open < n){
            solve(curr + '(',open+1,close,n,res);
        }
        if(close < open){
            solve(curr + ')',open,close+1,n,res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve("",0,0,n,res);
        return res;
    }
};
