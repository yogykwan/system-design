/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        children.clear();
        is_leaf = false;
    }

public:
    map<char, TrieNode*> children;
    bool is_leaf;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        char ch;
        for (int i = 0; ch = word[i]; ++i) {
            if (p->children.find(ch) == p->children.end()) {
                p->children[ch] = new TrieNode();
            }
            p = p->children[ch];
        }
        p->is_leaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        char ch;
        for (int i = 0; ch = word[i]; ++i) {
            if (p->children.find(ch) == p->children.end()) {
                return false;
            }
            p = p->children[ch];
        }
        return p->is_leaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        char ch;
        for (int i = 0; ch = prefix[i]; ++i) {
            if (p->children.find(ch) == p->children.end()) {
                return false;
            }
            p = p->children[ch];
        }
        return true;
    }

private:
    TrieNode* root;
};

