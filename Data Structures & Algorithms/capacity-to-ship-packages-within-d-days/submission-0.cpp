class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        int res = r;
        int n = weights.size();

        while(l<=r){
            int mid = l + (r - l)/2;
            int curr = 0, dayNeeded = 1;
            for(int i = 0; i<n; i++){
                if(curr + weights[i] > mid){
                    dayNeeded++;
                    curr = 0;  
                }
                curr += weights[i];
            }
            if(dayNeeded <= days){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return res;
    }
};