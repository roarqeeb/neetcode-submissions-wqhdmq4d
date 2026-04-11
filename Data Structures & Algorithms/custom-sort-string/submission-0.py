class Solution:
    def customSortString(self, order: str, s: str) -> str:
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1

        res = []
        for c in order:
            idx = ord(c) - ord('a')
            while count[idx]:
                res.append(c)
                count[idx] -= 1

        for idx in range(26):
            c = chr(ord('a') + idx)
            while count[idx]:
                count[idx] -= 1
                res.append(c)

        return ''.join(res)