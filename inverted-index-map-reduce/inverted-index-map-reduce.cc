/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done();
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 * Definition of Document:
 * class Document {
 * public:
 *     int id; // document id
 *     string content; // document content
 * }
 */
class InvertedIndexMapper: public Mapper {
public:
    void Map(Input<Document>* input) {
        // Write your code here
        // Please directly use func 'output' to output
        // the results into output buffer.
        // void output(string &key, int value);
        while (!input->done()) {
            Document d = input->value();
            string s = d.content, t;
            int id = d.id;
            int i = 0, j;
            while (i < s.length()) {
                j = s.find(' ', i);
                if (i == j) {
                    ++i;
                    continue;
                }
                if (j == string::npos) {
                    t = s.substr(i);
                    i = s.length();
                } else {
                    t = s.substr(i, j - i);
                    i = j + 1;
                }
                output(t, id);
            }
            input->next();
        }
    }
};


class InvertedIndexReducer: public Reducer {
public:
    void Reduce(string &key, Input<int>* input) {
        // Write your code here
        // Please directly use func 'output' to output
        // the results into output buffer.
        // void output(string &key, vector<int> &value);
        vector<int> ans;
        int pre = -1, cur;
        while (!input->done()) {
            cur = input->value();
            if (cur != pre) {
                ans.push_back(cur);
                pre = cur;
            }
            input->next();
        }
        output(key, ans);
    }
};
