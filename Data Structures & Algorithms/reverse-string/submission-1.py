class Solution(object):
    def reverseString(self, s):
        x = len(s)
        for i in range (x // 2):
    # def swap(s, a, b):
    #         temp = s[a]
    #         s[a] = s[b]
    #         s[b] = temp
            a = i
            b = x - 1 - i
            s[a], s[b] = s[b], s[a]
