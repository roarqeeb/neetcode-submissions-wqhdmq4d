class Solution:
    def maxSubArray(self, nums):
        cur=best= nums[0]
        for num in nums[1:]:
            cur = max(num,cur + num)
            best = max(best,cur)
        return best
