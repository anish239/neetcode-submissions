class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>st;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i<n; i++){
            int start = i;

            while(!st.empty() && st.top().second > heights[i]){
                auto [index,height] = st.top();
                st.pop();
                int area = height * (i - index);
                maxArea = max(maxArea,area);
                start = index;
            }
            st.push({start,heights[i]});
        }

        while(!st.empty()){
            auto [index,height] = st.top();
            st.pop();
            int area = height * (n - index);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};
