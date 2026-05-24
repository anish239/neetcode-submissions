class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>>st;
        string currString = "";
        int currNum = 0;

        for(auto x: s){
            if(isdigit(x)){
                currNum = currNum * 10 + (x - '0');
            }
            else if(x == '['){
                st.push({currString,currNum});
                currString = "";
                currNum = 0;
            }
            else if(x == ']'){
                auto [prev,k] = st.top();
                st.pop();
                string repeated = "";
                for (int i = 0; i < k; i++)
                    repeated += currString;
                currString = prev + repeated;
            }
            else{
                currString += x;
            }
        }
        return currString;
    }
};