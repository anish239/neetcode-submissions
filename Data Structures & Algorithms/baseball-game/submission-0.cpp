class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>st;

        for(auto op:operations){
            if(op == "C"){
                st.pop_back();
            }
            else if(op == "D"){
                st.push_back(st.back() * 2);
            }
            else if(op == "+"){
                int top = st.back();
                int top2 = st[st.size()-2];
                st.push_back(top + top2);
            }
            else{
                st.push_back(stoi(op));
            }
        }
        int sum = 0;
        for(auto x:st){
            sum += x;
        }
        return sum;
    }
};