class Solution {
    vector<vector<int>> memo;

public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        memo.assign(n, vector<int>(2, -1));

        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            maxLen = max(maxLen, dfs(i, true, arr));
            maxLen = max(maxLen, dfs(i, false, arr));
        }

        return maxLen;
    }

    int dfs(int i, bool sign, vector<int>& arr) {
        int signIndex = sign ? 1 : 0;
        if (i == arr.size() - 1) return 1;
        if (memo[i][signIndex] != -1) {
            return memo[i][signIndex];
        }

        int res = 1;
        if ((sign && arr[i] > arr[i + 1]) ||
            (!sign && arr[i] < arr[i + 1])) {
            res = 1 + dfs(i + 1, !sign, arr);
        }

        memo[i][signIndex] = res;
        return res;
    }
};