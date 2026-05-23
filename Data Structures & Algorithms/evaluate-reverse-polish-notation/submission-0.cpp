class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& x : tokens) {
            if (x == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 + top1);
            }
            else if (x == "-") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 - top1);
            }
            else if (x == "*") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 * top1);
            }
            else if (x == "/") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 / top1);
            }
            else {
                st.push(stoi(x));
            }
        }

        return st.top();
    }
};
