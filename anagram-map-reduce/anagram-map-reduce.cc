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
 */
class AnagramMapper: public Mapper {
public:
    void Map(Input<string>* input) {
        // Write your code here
        // Please directly use func 'output' to output
        // the results into output buffer.
        // void output(string &key, string& value);
        while (!input->done()) {
            string line = input->value();
            int i = 0, j;
            string s, t;
            while (i < line.length()) {
                j = line.find(' ', i);
                if (j == i) {
                    ++i;
                    continue;
                }
                if (j == string::npos) {
                    s = line.substr(i);
                    i = line.length();
                } else {
                    s = line.substr(i, j - i);
                    i = j + 1;
                }
                t = s;
                sort(t.begin(), t.end());
                output(t, s);
            }
            input->next();
        }
    }
};


class AnagramReducer: public Reducer {
public:
    void Reduce(string &key, Input<string>* input) {
        // Write your code here
        // Please directly use func 'output' to output
        // the results into output buffer.
        // void output(string &key, vector<string>& value);
        vector<string> ans;
        while (!input->done()) {
            ans.push_back(input->value());
            input->next();
        }
        output(key, ans);
    }
};
