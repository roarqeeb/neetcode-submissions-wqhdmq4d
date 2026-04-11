class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        self.heapSort(nums)
        return nums

    def heapify(self, arr, n, i):
        l = (i << 1) + 1
        r = (i << 1) + 2
        largestNode = i

        if l < n and arr[l] > arr[largestNode]:
            largestNode = l

        if r < n and arr[r] > arr[largestNode]:
            largestNode = r

        if largestNode != i:
            arr[i], arr[largestNode] = arr[largestNode], arr[i]
            self.heapify(arr, n, largestNode)

    def heapSort(self, arr):
        n = len(arr)
        for i in range(n // 2 - 1, -1, -1):
            self.heapify(arr, n, i)

        for i in range(n - 1, 0, -1):
            arr[0], arr[i] = arr[i], arr[0]
            self.heapify(arr, i, 0)