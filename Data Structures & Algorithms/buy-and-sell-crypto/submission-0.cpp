class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        int n = prices.size();

        for(int i = 0; i<n; i++){
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit,profit);
            minPrice = min(minPrice,prices[i]);
        }
        return maxProfit;
    }
};
