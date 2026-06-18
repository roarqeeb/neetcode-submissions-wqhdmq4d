class Solution {
public:
    vector<int> dp;

    int numSquares(int n) {
        dp.assign(n + 1, -1);
        dp[0] = 0;
        return dfs(n);
    }

private:
    int dfs(int target) {
        if (dp[target] != -1) {
            return dp[target];
        }

        int res = target; // worst case: 1^2 used target times

        for (int i = 1; i * i <= target; i++) {
            res = min(res, 1 + dfs(target - i * i));
        }

        return dp[target] = res;
    }
};