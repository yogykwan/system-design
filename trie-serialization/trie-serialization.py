"""
    Definition of TrieNode:
    class TrieNode:
    def __init__(self):
    # <key, value>: <Character, TrieNode>
    self.children = collections.OrderedDict()
    """
class Solution:
    
    '''
        @param root: An object of TrieNode, denote the root of the trie.
        This method will be invoked first, you should design your own algorithm
        to serialize a trie which denote by a root node to a string which
        can be easily deserialized by your own "deserialize" method later.
        '''
    def serialize(self, root):
        # Write your code here
        def dfs(parent):
            ans = "<"
            for key in parent.children:
                value = parent.children[key]
                ans += key
                ans += dfs(value)
            ans += ">"
            return ans
        
        return dfs(root)
    
    
    '''
        @param data: A string serialized by your serialize method.
        This method will be invoked second, the argument data is what exactly
        you serialized at method "serialize", that means the data is not given by
        system, it's given by your own serialize method. So the format of data is
        designed by yourself, and deserialize it here as you serialize it in
        "serialize" method.
        '''
    def deserialize(self, data):
        # Write your code here
        def dfs(parent, str):
            le = len(str)
            i = 1
            while i < le:
                if str[i] != '<' and str[i] != '>':
                    child = TrieNode()
                    parent.children[str[i]] = child
                    j = i + 1
                    cnt = 0
                    while j < le:
                        if str[j] == '<':
                            cnt += 1
                        elif str[j] == '>':
                            cnt -= 1
                        if cnt == 0:
                            break
                        j += 1
                    dfs(child, str[i + 1: j + 1])
                    i = j
                i += 1
        
        root = TrieNode()
        dfs(root, data)
    return root
