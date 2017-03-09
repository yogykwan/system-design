class Node:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None


class LRUCache:
    
    # @param capacity, an integer
    def __init__(self, capacity):
        # write your code here
        self.capacity = capacity
        self.head = Node()
        self.tail = self.head
        self.key_pa = dict()
    
    # @move the latest to the end of link
    def move(self, key):
        pa = self.key_pa[key]
        cur = pa.next
        if cur != self.tail:
            pa.next = cur.next
            self.key_pa[cur.next.key] = pa
            self.key_pa[key] = self.tail
            self.tail.next = cur
            self.tail = cur
            cur.next = None

# @return an integer
def get(self, key):
    # write your code here
    if key in self.key_pa:
        self.move(key)
            return self.tail.value
        else:
            return -1
                
                # @param key, an integer
                # @param value, an integer
                # @return nothing
                def set(self, key, value):
                    # write your code here
if key in self.key_pa:
    self.move(key)
        self.tail.value = value
        else:
            cur = Node(key, value)
            self.key_pa[key] = self.tail
            self.tail.next = cur
            self.tail = cur
            if len(self.key_pa) > self.capacity:
                del self.key_pa[self.head.next.key]
                self.head.next = self.head.next.next
                self.key_pa[self.head.next.key] = self.head
