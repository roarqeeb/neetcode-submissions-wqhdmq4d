class Solution {
public:
    vector<vector<int>> dp;

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n, vector<int>(amount + 1, -1));

        return dfs(coins, 0, amount);
    }

private:
    int dfs(vector<int>& coins, int i, int amount) {
        if (amount == 0) {
            return 1;
        }

        if (i == coins.size()) {
            return 0;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int res = dfs(coins, i + 1, amount);  // skip coin

        if (coins[i] <= amount) {
            res += dfs(coins, i, amount - coins[i]); // take coin
        }

        return dp[i][amount] = res;
    }
};