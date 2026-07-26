class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;

        // append all the elements in the given direction
        dfs(m, n, 0, -1, 0, 1, matrix, res);
        return res;
    }

    void dfs(int row, int col, int r, int c, int dr, int dc,
             vector<vector<int>>& matrix, vector<int>& res) {
        if (row == 0 || col == 0) return;

        for (int i = 0; i < col; i++) {
            r += dr;
            c += dc;
            res.push_back(matrix[r][c]);
        }

        // sub-problem
        dfs(col, row - 1, r, c, dc, -dr, matrix, res);
    }
};