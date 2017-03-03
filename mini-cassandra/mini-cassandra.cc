/**
 * Definition of Column:
 * class Column {
 * public:
 *     int key;
 *     String value;
 *     Column(int key, string value) {
 *         this->key = key;
 *         this->value = value;
 *    }
 * }
 */
class MiniCassandra {
    public:
    MiniCassandra() {
        // initialize your data structure here.
        hashs.clear();
        cols.clear();
    }
    
    /**
     * @param raw_key a string
     * @param column_start an integer
     * @param column_end an integer
     * @return void
     */
    void insert(string raw_key, int column_key, string column_value) {
        // Write your code here
        hashs[raw_key].insert(column_key);
        cols[raw_key][column_key] = column_value;
    }
    
    /**
     * @param raw_key a string
     * @param column_start an integer
     * @param column_end an integer
     * @return a list of Columns
     */
    vector<Column> query(string raw_key, int column_start, int column_end) {
        // Write your code here
        vector<Column> ans;
        if (hashs.find(raw_key) == hashs.end()) {
            return ans;
        }
        set<int>::iterator it = hashs[raw_key].lower_bound(column_start);
        if (it == hashs[raw_key].end()) {
            return ans;
        }
        for (; it != hashs[raw_key].end() && *it <= column_end; ++it) {
            ans.push_back(Column(*it, cols[raw_key][*it]));
        }
        return ans;
    }
    
    private:
    map<string, set<int>> hashs;
    map<string, map<int, string>> cols;
};
