class Solution {
    private:
    vector<vector<string>>result;
    vector<string>path;

    bool isPalidrome(string &s,int left, int right){
        while(left<right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void backtrack(string &s,int start){
        if(start == s.size()){
            result.push_back(path);
            return;
        }
        
        for(int end = start; end<s.size(); end++){
            if(isPalidrome(s,start,end)){
                path.push_back(s.substr(start,end-start+1));
                backtrack(s,end+1);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return result;
    }
};
