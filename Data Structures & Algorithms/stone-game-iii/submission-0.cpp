class Solution {
    vector<vector<int>> dp;
    int n;

public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, vector<int>(2, INT_MIN));

        int result = dfs(0, 1, stoneValue);
        if (result == 0) return "Tie";
        return result > 0 ? "Alice" : "Bob";
    }

private:
    int dfs(int i, int alice, vector<int>& stoneValue) {
        if (i >= n) return 0;
        if (dp[i][alice] != INT_MIN) return dp[i][alice];

        int res = alice == 1 ? INT_MIN : INT_MAX;
        int score = 0;
        for (int j = i; j < min(i + 3, n); j++) {
            if (alice == 1) {
                score += stoneValue[j];
                res = max(res, score + dfs(j + 1, 0, stoneValue));
            } else {
                score -= stoneValue[j];
                res = min(res, score + dfs(j + 1, 1, stoneValue));
            }
        }

        dp[i][alice] = res;
        return res;
    }
};