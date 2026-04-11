class Solution:
    def findLucky(self, arr: List[int]) -> int:
        res = -1

        for num in arr:
            cnt = 0
            for a in arr:
                if num == a:
                    cnt += 1
            if cnt == num:
                res = max(res, num)

        return res