class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.cnt = 0
        self.next = None


class LFUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        # write your code here
        self.capacity = capacity
        self.len = 0
        self.root = Node(None, None)
        self.key_pa = {}
        self.cnt_last = {0: self.root}

    def up(self, pa):
        cur = pa.next
        cur.cnt += 1
        if self.cnt_last[cur.cnt - 1] == cur:
            if pa.cnt == cur.cnt - 1:
                self.cnt_last[cur.cnt - 1] = pa
            else:
                del self.cnt_last[cur.cnt - 1]
        if cur.next and cur.next.cnt <= cur.cnt:
            if cur.next.cnt == cur.cnt:
                pd = self.cnt_last[cur.cnt]
            else:
                if cur.cnt in self.cnt_last:
                    pd = self.cnt_last[cur.cnt]
                else:
                    pd = self.cnt_last[cur.cnt - 1]
            pa.next = cur.next
            cur.next = pd.next
            pd.next = cur
            self.key_pa[pa.next.key] = pa
            self.key_pa[pd.next.key] = pd
            if cur.next:
                self.key_pa[cur.next.key] = cur
        self.cnt_last[cur.cnt] = cur

    def push(self, cur):
        self.len += 1
        if self.root.next:
            self.key_pa[self.root.next.key] = cur
            cur.next = self.root.next
        self.root.next = cur
        self.key_pa[cur.key] = self.root
        self.cnt_last[0] = cur
        self.up(self.root)

    def pop(self):
        self.len -= 1
        cur = self.root.next
        del self.key_pa[cur.key]
        self.root.next = cur.next
        if cur.next:
            self.key_pa[cur.next.key] = self.root
        if self.cnt_last[cur.cnt] == cur:
            del self.cnt_last[cur.cnt]
        del cur

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        # write your code here
        if key in self.key_pa:
            pa = self.key_pa[key]
            pa.next.value = value
            self.up(pa)
        else:
            if self.len == self.capacity:
                self.pop()
            cur = Node(key, value)
            self.push(cur)

    # @return an integer
    def get(self, key):
        # write your code here
        if key in self.key_pa:
            pa = self.key_pa[key]
            ans = pa.next.value
            self.up(pa)
            return ans
        else:
            return -1

