class Typeahead {
public:
    // @param dict: A dictionary of words dict
    Typeahead(unordered_set<string> &dict) {
        // do initialize if necessary
        for (auto &s : dict) {
            int l = s.length();
            for (int i = 0; i < l; ++i) {
                for (int j = 1; j <= l - i; ++j) {
                    string t = s.substr(i, j);
                    if (word_dict.find(t) == word_dict.end()) {
                        word_dict[t] = vector<string>{s};
                    } else if (*(word_dict[t].end() - 1) != s) {
                        word_dict[t].push_back(s);
                    }
                }
            }
        }
    }

    // @param str: a string
    // @return a set of words
    vector<string> search(string &str) {
        // Write your code here
        if (word_dict.find(str) != word_dict.end()) {
            return word_dict[str];
        } else {
            return vector<string>();
        }
    }

private:
    map<string, vector<string>> word_dict;
};

