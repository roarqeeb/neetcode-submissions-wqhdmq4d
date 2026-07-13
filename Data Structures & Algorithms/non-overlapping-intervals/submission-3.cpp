class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int n = intervals.size();
        vector<int> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            int idx = bs(i, intervals[i][0], intervals);
            if (idx == 0) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = max(dp[i - 1], 1 + dp[idx - 1]);
            }
        }
        return n - dp[n - 1];
    }

    int bs(int r, int target, vector<vector<int>>& intervals) {
        int l = 0;
        while (l < r) {
            int m = (l + r) >> 1;
            if (intervals[m][1] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};