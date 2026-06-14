class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visit(n, false);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (__gcd(nums[i], nums[j]) > 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        dfs(0, adj, visit);
        for (bool node : visit) {
            if (!node) {
                return false;
            }
        }
        return true;
    }

private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        visit[node] = true;
        for (int& nei : adj[node]) {
            if (!visit[nei]) {
                dfs(nei, adj, visit);
            }
        }
    }
};