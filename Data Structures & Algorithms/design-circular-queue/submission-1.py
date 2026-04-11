class MyCircularQueue:

    def __init__(self, k):
        self.q = []
        self.k = k

    def enQueue(self, value):
        if len(self.q) == self.k:
            return False
        self.q.append(value)
        return True

    def deQueue(self):
        if not self.q:
            return False
        self.q.pop(0)
        return True

    def Front(self):
        if self.q:
            return self.q[0]
        return -1

    def Rear(self):
        if self.q:
            return self.q[-1]
        return -1

    def isEmpty(self):
        return len(self.q) == 0

    def isFull(self):
        return len(self.q) == self.k