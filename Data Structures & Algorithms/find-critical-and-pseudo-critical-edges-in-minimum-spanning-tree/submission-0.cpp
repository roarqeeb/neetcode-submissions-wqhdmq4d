class UnionFind {
public:
    vector<int> par, rank;

    UnionFind(int n) : par(n), rank(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        if (v != par[v]) {
            par[v] = find(par[v]);
        }
        return par[v];
    }

    bool unionSets(int v1, int v2) {
        int p1 = find(v1), p2 = find(v2);
        if (p1 == p2) return false;
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<array<int, 4>> edgeList;
        for (int i = 0; i < edges.size(); ++i) {
            edgeList.push_back({ edges[i][0], edges[i][1], edges[i][2], i });
        }

        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        int mstWeight = 0;
        UnionFind uf(n);
        for (auto& edge : edgeList) {
            if (uf.unionSets(edge[0], edge[1])) {
                mstWeight += edge[2];
            }
        }

        vector<int> critical, pseudo;
        for (auto& edge : edgeList) {
            // Try without current edge
            UnionFind ufWithout(n);
            int weight = 0;
            for (auto& other : edgeList) {
                if (other[3] != edge[3] && ufWithout.unionSets(other[0], other[1])) {
                    weight += other[2];
                }
            }
            if (*max_element(ufWithout.rank.begin(), ufWithout.rank.end()) != n || weight > mstWeight) {
                critical.push_back(edge[3]);
                continue;
            }

            // Try with current edge
            UnionFind ufWith(n);
            ufWith.unionSets(edge[0], edge[1]);
            weight = edge[2];
            for (auto& other : edgeList) {
                if (ufWith.unionSets(other[0], other[1])) {
                    weight += other[2];
                }
            }
            if (weight == mstWeight) {
                pseudo.push_back(edge[3]);
            }
        }

        return { critical, pseudo };
    }
};