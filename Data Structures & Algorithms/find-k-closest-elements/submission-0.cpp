class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int L = 0, R = arr.size() - k;

        while (L < R) {
            int mid = L + (R - L) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
                L = mid + 1;
            else
                R = mid;
        }
        return vector<int>(arr.begin() + L, arr.begin() + L + k);
    }
};