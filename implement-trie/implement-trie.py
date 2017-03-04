"""
    Your Trie object will be instantiated and called as such:
    trie = Trie()
    trie.insert("lintcode")
    trie.search("lint") will return false
    trie.startsWith("lint") will return true
    """
class TrieNode:
    def __init__(self):
    # Initialize your data structure here.
    self.children = dict()
    self.is_leaf = False


class Trie:
    def __init__(self):
    self.root = TrieNode()
        
        # @param {string} word
        # @return {void}
        # Inserts a word into the trie.
        def insert(self, word):
            p = self.root
for ch in word:
    if ch not in p.children:
        p.children[ch] = TrieNode()
            p = p.children[ch]
        p.is_leaf = True
            
            # @param {string} word
            # @return {boolean}
            # Returns if the word is in the trie.
            def search(self, word):
p = self.root
    for ch in word:
        if ch not in p.children:
        return False
            p = p.children[ch]
        return p.is_leaf
            
            # @param {string} prefix
            # @return {boolean}
            # Returns if there is any word in the trie
            # that starts with the given prefix.
            def startsWith(self, prefix):
p = self.root
    for ch in prefix:
        if ch not in p.children:
        return False
            p = p.children[ch]
        return True
