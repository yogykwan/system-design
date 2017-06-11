def cmp_words(a, b):
    if a[1] != b[1]:
        return b[1] - a[1]
    return cmp(a[0], b[0])


class HashHeap:
    def __init__(self):
        self.hash = {}
        self.heap = [0]
    
    def add(self, key, val):
        self.heap[0] += 1
        self.hash[key] = self.heap[0]
        self.heap.append((key, val))
        self._siftup(self.heap[0])
    
    def remove(self, key):
        index = self.hash[key]
        self._swap(self.heap[0], index)
        del self.hash[self.heap[self.heap[0]][0]]
        self.heap.pop()
        self.heap[0] -= 1
        if index <= self.heap[0]:
            index = self._siftup(index)
            self._siftdown(index)

    def has(self, key):
        return key in self.hash
    
    def size(self):
        return self.heap[0]
    
    def pop(self):
        key, value = self.heap[1]
        self.remove(key)
        return value
    
    def _swap(self, a, b):
        self.heap[a], self.heap[b] = self.heap[b], self.heap[a]
        self.hash[self.heap[a][0]] = a
        self.hash[self.heap[b][0]] = b
    
    def _siftup(self, index):
        while index != 1:
            if cmp_words(self.heap[index], self.heap[index / 2]) < 0:
                break
            self._swap(index, index / 2)
            index = index / 2
        return index
    
    def _siftdown(self, index):
        size = self.heap[0]
        while index < size:
            t = index
            if index * 2 <= size and cmp_words(self.heap[t], self.heap[index * 2]) < 0:
                t = index * 2
            if index * 2 + 1 <= size and cmp_words(self.heap[t], self.heap[index * 2 + 1]) < 0:
                t = index * 2 + 1
            if t == index:
                break
            self._swap(index, t)
            index = t
        return index

class TopK:
    # @param {int} k an integer
    def __init__(self, k):
        # initialize your data structure here
        self.k = k
        self.hh = HashHeap()
        self.records = {}
    
    # @param {str} word a string
    def add(self, word):
        # Write your code here
        if word in self.records:
            if self.hh.has(word):
                self.hh.remove(word)
            self.records[word] += 1
        else:
            self.records[word] = 1
        self.hh.add(word, self.records[word])
        if self.hh.size() > self.k:
            self.hh.pop();

    # @return {str[]} the current top k frequent word
    def topk(self):
        # Write your code here
        ans = self.hh.heap[1:]
            ans.sort(cmp=cmp_words)
            strs =  [i[0] for i in ans]
            return strs
