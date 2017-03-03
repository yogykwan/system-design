"""
    Definition of TrieNode:
    class TrieNode:
    def __init__(self):
    # <key, value>: <Character, TrieNode>
    self.children = collections.OrderedDict()
    self.top10 = []
    """


class TrieService:
    
    def __init__(self):
        self.root = TrieNode()
    
    def get_root(self):
        # Return root of trie root, and
        # lintcode will print the tree struct.
        return self.root
    
    # @param {str} word a string
    # @param {int} frequency an integer
    # @return nothing
    def insert(self, word, frequency):
        # Write your your code here
        p = self.root
        for c in word:
            if c not in p.children:
                p.children[c] = TrieNode()
            p = p.children[c]
            if len(p.top10) == 10:
                p.top10[9] = max(p.top10[9], frequency)
            else:
                p.top10.append(frequency)
            p.top10.sort(reverse=True)
