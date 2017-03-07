/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 * };
 */

class Solution {
public:
    string serialize_dfs(TrieNode* root) {
        string ans = "<";
        for (map<char, TrieNode*>::iterator it = root->children.begin();
             it != root->children.end(); ++it) {
            string tmp = " ";
            tmp[0] = it->first;
            tmp += serialize_dfs(it->second);
            ans += tmp;
        }
        return ans + ">";
    }
    
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a trie which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TrieNode* root) {
        // Write your code here
        return serialize_dfs(root);
    }
    
    void deserialize_dfs(TrieNode* root, string data, char fa = ' ') {
        int len = data.length();
        for (int i = 1; i < len; ++i) {
            if (data[i] != '<' && data[i] != '>') {
                TrieNode *child = new TrieNode();
                root->children[data[i]] = child;
                int j, cnt = 0;
                for (j = i + 1; j < len; ++j) {
                    if (data[j] == '<') ++cnt;
                    else if (data[j] == '>') --cnt;
                    if (cnt == 0) {
                        break;
                    }
                }
                deserialize_dfs(child, data.substr(i + 1, j - i), data[i]);
                i = j;
            }
        }
    }
    
    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TrieNode* deserialize(string data) {
        // Write your code here
        TrieNode *root = new TrieNode();
        deserialize_dfs(root, data);
        return root;
    }
};
