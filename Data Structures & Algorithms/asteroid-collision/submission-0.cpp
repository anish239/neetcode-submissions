class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int x : asteroids) {
            bool survived = true;

            while (!st.empty() && x < 0 && st.top() > 0) {  
                if (st.top() < abs(x)) {
                    st.pop();
                }
                else if (st.top() == abs(x)) {  
                    st.pop();
                    survived = false;
                    break;
                }
                else {
                    survived = false;
                    break;
                }
            }

            if (survived) st.push(x);
        }
        vector<int> result(st.size());
        for (int i = result.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};