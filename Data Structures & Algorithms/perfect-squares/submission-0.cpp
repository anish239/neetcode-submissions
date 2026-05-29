class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++)
            squares.push_back(i * i);

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int s = 1; s <= n; s++)
            for (int sq : squares) {
                if (sq > s) break;          
                if (dp[s - sq] != INT_MAX)
                    dp[s] = min(dp[s], dp[s - sq] + 1);
            }

        return dp[n];
    }
};