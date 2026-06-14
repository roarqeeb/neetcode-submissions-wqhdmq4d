class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topoSort(k, rowConditions);
        if (rowOrder.empty()) return {};
        vector<int> colOrder = topoSort(k, colConditions);
        if (colOrder.empty()) return {};

        unordered_map<int, int> valToRow, valToCol;
        for (int i = 0; i < rowOrder.size(); i++) {
            valToRow[rowOrder[i]] = i;
        }
        for (int i = 0; i < colOrder.size(); i++) {
            valToCol[colOrder[i]] = i;
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        for (int num = 1; num <= k; num++) {
            int r = valToRow[num];
            int c = valToCol[num];
            res[r][c] = num;
        }
        return res;
    }

private:
    unordered_set<int> visit;
    unordered_set<int> path;
    vector<int> order;

    vector<int> topoSort(int k, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (int i = 1; i <= k; i++) {
            adj[i] = {};
        }
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        visit.clear();
        path.clear();
        order.clear();
        for (int i = 1; i <= k; i++) {
            if (visit.find(i) == visit.end()) {
                if (!dfs(i, adj)) {
                    return {};
                }
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }

    bool dfs(int src, unordered_map<int, vector<int>>& adj) {
        if (path.find(src) != path.end()) return false;
        if (visit.find(src) != visit.end()) return true;

        visit.insert(src);
        path.insert(src);
        for (int nei : adj[src]) {
            if (!dfs(nei, adj)) {
                return false;
            }
        }
        path.erase(src);
        order.push_back(src);
        return true;
    }
};