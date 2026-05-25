class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        int m = nums1.size();
        int n = nums2.size();
        int l = 0, r = m;
        
        while (l <= r) {
            int i = (l + r) / 2;
            int j = (m + n) / 2 - i;
            
            int leftMax1  = (i == 0) ? INT_MIN : nums1[i - 1];
            int rightMin1 = (i == m) ? INT_MAX : nums1[i];
            int leftMax2  = (j == 0) ? INT_MIN : nums2[j - 1];
            int rightMin2 = (j == n) ? INT_MAX : nums2[j];
            
            if (leftMax1 > rightMin2)
                r = i - 1;
            else if (leftMax2 > rightMin1)
                l = i + 1;
            else {
                if ((m + n) % 2 == 1)
                    return min(rightMin1, rightMin2);
                else
                    return (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2.0;
            }
        }
        return 0.0;
    }
};
