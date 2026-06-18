class Solution {
private:
    vector<vector<int>> dp;

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return dfs(0, 0, grid);
    }

    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r == grid.size() - 1 && c == grid[0].size() - 1) {
            return grid[r][c];
        }
        if (r == grid.size() || c == grid[0].size()) {
            return INT_MAX;
        }
        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        dp[r][c] = grid[r][c] + min(dfs(r + 1, c, grid), dfs(r, c + 1, grid));
        return dp[r][c];
    }
};