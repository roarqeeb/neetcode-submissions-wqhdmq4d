class Solution:
    def convertToTitle(self, cl: int) -> str:
        res = []
        while cl > 0:
            cl -= 1
            offset = cl % 26
            res += chr(ord('A') + offset)
            cl //= 26

        return ''.join(reversed(res))        