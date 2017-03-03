/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 *     vector<int> top10;
 * };
 */
class TrieService {
    private:
    TrieNode* root;
    
    public:
    TrieService() {
        root = new TrieNode();
    }
    
    TrieNode* getRoot() {
        // Return root of trie root, and
        // lintcode will print the tree struct.
        return root;
    }
    
    void insert(string& word, int frequency) {
        // Write your code here
        TrieNode *p = root;
        for (int i = 0; word[i]; ++i) {
            if (p->children.find(word[i]) == p->children.end()) {
                p->children[word[i]] = new TrieNode();
            }
            vector<int> &top = p->children[word[i]]->top10;
            if (top.size() == 10) {
                if (top[9] < frequency) {
                    top[9] = frequency;
                }
            } else {
                top.push_back(frequency);
            }
            sort(top.begin(), top.end());
            reverse(top.begin(), top.end());
            p = p->children[word[i]];
        }
    }
};
