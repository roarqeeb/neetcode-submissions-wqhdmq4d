class Solution {
public:
    vector<vector<int>> dp;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));

        return dfs(0, 1, prices);
    }

private:
    int dfs(int i, int buying, vector<int>& prices) {
        if (i >= prices.size()) {
            return 0;
        }

        if (dp[i][buying] != -1) {
            return dp[i][buying];
        }

        int cooldown = dfs(i + 1, buying, prices);

        if (buying) {
            int buy = dfs(i + 1, 0, prices) - prices[i];
            return dp[i][buying] = max(buy, cooldown);
        } else {
            int sell = dfs(i + 2, 1, prices) + prices[i];
            return dp[i][buying] = max(sell, cooldown);
        }
    }
};