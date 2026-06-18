class Solution {
public:
    int integerBreak(int n) {
        return dfs(n, n - 1);
    }

private:
    int dfs(int num, int i) {
        if (min(num, i) == 0) {
            return 1;
        }

        if (i > num) {
            return dfs(num, num);
        }

        return max(i * dfs(num - i, i), dfs(num, i - 1));
    }
};