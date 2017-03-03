/**
 * Definition of Document:
 * class Document {
 * public:
 *     int id;
 *     string content;
 * }
 */
class Solution {
public:
    /**
     * @param docs a list of documents
     * @return an inverted index
     */
    map<string, vector<int>> invertedIndex(vector<Document>& docs) {
        // Write your code here
        map<string, vector<int>> ans;
        for (vector<Document>::iterator it = docs.begin(); it != docs.end(); ++it) {
            stringstream ss(it->content);
            string word;
            while (ss >> word) {
                if (ans.find(word) == ans.end()) {
                    ans[word] = vector<int>();
                }
                if (find(ans[word].begin(), ans[word].end(), it->id) == ans[word].end()) {
                    ans[word].push_back(it->id);
                }
            }
        }
        return ans;
    }
};

