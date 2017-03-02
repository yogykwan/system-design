class Memcache:
    
    def __init__(self):
        # initialize your data structure here.
        self.items = dict()
        self.INF = 2147483647
    
    # @param {int} curtTime an integer
    # @param {int} key an integer
    # @return an integer
    def get(self, curtTime, key):
        # Write your code here
        if key in self.items:
            if self.items[key][1] == -1 or self.items[key][1] > curtTime:
                return self.items[key][0]
            else:
                self.items.pop(key)
        return self.INF
    
    # @param {int} curtTime an integer
    # @param {int} key an integer
    # @param {int} value an integer
    # @param {int} ttl an integer
    # @return nothing
    def set(self, curtTime, key, value, ttl):
        # Write your code here
        if ttl == 0:
            expire = -1
        else:
            expire = curtTime + ttl
        self.items[key] = [value, expire]
    
    # @param {int} curtTime an integer
    # @param {int} key an integer
    # @return nothing
    def delete(self, curtTime, key):
        # Write your code here
        if key in self.items:
            self.items.pop(key)

# @param {int} curtTime an integer
# @param {int} key an integer
# @param {int} delta an integer
# @return an integer
def incr(self, curtTime, key, delta):
    # Write your code here
    if key in self.items:
        if self.items[key][1] == -1 or self.items[key][1] > curtTime:
            self.items[key][0] += delta
                return self.items[key][0]
            else:
                self.items.pop(key)
    return self.INF

# @param {int} curtTime an integer
# @param {int} key an integer
# @param {int} delta an integer
# @return an integer
def decr(self, curtTime, key, delta):
    # Write your code here
    if key in self.items:
        if self.items[key][1] == -1 or self.items[key][1] > curtTime:
            self.items[key][0] -= delta
                return self.items[key][0]
            else:
                self.items.pop(key)
    return self.INF
