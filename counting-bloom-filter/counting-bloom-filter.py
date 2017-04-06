class HashFunction(object):
    def __init__(self, m, b):
        self.mod = m
        self.base = b
    
    def get_hash(self, s):
        ans = 0
        for i in xrange(len(s)):
            ans = (ans * self.base + ord(s[i])) % self.mod
        return ans

class CountingBloomFilter:
    
    # @param {int} k an integer
    def __init__(self, k):
        # initialize your data structure here
        self.k = k
        self.hfs = []
        for i in xrange(k):
            self.hfs.append(HashFunction(100000 + i, 2 * i + 3))
        self.bits =  [0] * 200000
    
    
    # @param {str} word a string
    def add(self, word):
        # Write your code here
        for i in xrange(self.k):
            h = self.hfs[i].get_hash(word)
            self.bits[h] += 1

# @param {str} word a string
def remove(self, word):
    # Write your code here
    for i in xrange(self.k):
        h = self.hfs[i].get_hash(word)
            self.bits[h] -= 1

# @param {str} word a string
# @return {bool} True if word is exists in bllom filter or false
def contains(self, word):
    # Write your code here
    for i in xrange(self.k):
        h = self.hfs[i].get_hash(word)
            if not self.bits[h]:
                return False
    return True
