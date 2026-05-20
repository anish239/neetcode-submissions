class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s1 = nums1.size();
        int s2 = nums2.size();

        int i = 0;
        int j = 0;

        vector<int>arr;
        while(i<m && j<n){
            if(nums1[i] > nums2[j]){
                arr.push_back(nums2[j]);
                j++;
            }
            else{
                arr.push_back(nums1[i]);
                i++;
            }
        }
        while(i<m){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            arr.push_back(nums2[j]);
            j++;
        }
        for(int i = 0; i<arr.size();i++){
            nums1[i] = arr[i];
        }
    }
};