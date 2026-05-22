class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size() - 1;
        int maxL = 0, maxR = 0;
        int water = 0;

        while (L <= R) {
            if (maxL < maxR) {
                maxL = max(maxL, height[L]);
                water += maxL - height[L];
                L++;
            } else {
                maxR = max(maxR, height[R]);
                water += maxR - height[R];  
                R--;
            }
        }
        return water;
    }
};
