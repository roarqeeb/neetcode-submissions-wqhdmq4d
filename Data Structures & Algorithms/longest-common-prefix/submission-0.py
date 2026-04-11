class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        x = strs[0]
        n = len(strs)
        for i in range(1, n):
            temp = strs[i]
            minLen = min(len(temp), len(x))
            ansTemp = ""
            for j in range(minLen):
                if x[j] == temp[j]:
                    ansTemp += x[j]
                else:
                    break
            x = ansTemp
        return x
