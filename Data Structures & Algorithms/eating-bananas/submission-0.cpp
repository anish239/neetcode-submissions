class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int result = *max_element(piles.begin(),piles.end());

        while(l <= r){
            int mid = l + (r - l)/2;
            int total = 0;
            for(int i = 0; i<piles.size(); i++){
                int hours = (piles[i] + mid - 1) / mid;
                total += hours;
            }
            if(total <= h){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return result;
    }
};
