class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        def zAlgorithm(word1: str, word2: str) -> int:
            s = word2 + "$" + word1
            n = len(s)
            z = [0] * n
            l, r = 0, 0

            for i in range(1, n):
                if i <= r:
                    z[i] = min(r - i + 1, z[i - l])
                while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                    z[i] += 1
                if i + z[i] - 1 > r:
                    l, r = i, i + z[i] - 1

            for i in range(len(word2) + 1, n):
                if z[i] == len(word2):
                    return i - len(word2) - 1

            return -1

        res = []
        words.sort(key=len)

        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if zAlgorithm(words[j], words[i]) != -1:
                    res.append(words[i])
                    break

        return res       