# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        if not root:
            return None

        stack = []
        cur = root
        visited = None

        while stack or cur:
            while cur:
                stack.append(cur)
                cur = cur.left

            cur = stack[-1]
            if cur.right and cur.right != visited:
                cur = cur.right
                continue

            stack.pop()
            if not cur.left and not cur.right and cur.val == target:
                if not stack:
                    return None

                parent = stack[-1]
                if parent.left == cur:
                    parent.left = None
                elif parent.right == cur:
                    parent.right = None
            else:
                visited = cur

            cur = None

        return root