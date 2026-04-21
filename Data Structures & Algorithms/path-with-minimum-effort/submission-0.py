class DSU:
    def __init__(self, n):
        self.Parent = list(range(n + 1))
        self.Size = [1] * (n + 1)

    def find(self, node):
        if self.Parent[node] != node:
            self.Parent[node] = self.find(self.Parent[node])
        return self.Parent[node]

    def union(self, u, v):
        pu = self.find(u)
        pv = self.find(v)
        if pu == pv:
            return False
        if self.Size[pu] < self.Size[pv]:
            pu, pv = pv, pu
        self.Size[pu] += self.Size[pv]
        self.Parent[pv] = pu
        return True


class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        ROWS, COLS = len(heights), len(heights[0])
        edges = []
        for r in range(ROWS):
            for c in range(COLS):
                if r + 1 < ROWS:
                    edges.append((abs(heights[r][c] - heights[r + 1][c]), r * COLS + c, (r + 1) * COLS + c))
                if c + 1 < COLS:
                    edges.append((abs(heights[r][c] - heights[r][c + 1]), r * COLS + c, r * COLS + c + 1))

        edges.sort()
        dsu = DSU(ROWS * COLS)
        for weight, u, v in edges:
            dsu.union(u, v)
            if dsu.find(0) == dsu.find(ROWS * COLS - 1):
                return weight
        return 0