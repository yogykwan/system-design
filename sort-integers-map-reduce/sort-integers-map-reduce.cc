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
class SortIntegersMapper: public Mapper {
    public:
    void Map(int _, Input<vector<int>>* input) {
        // Write your code here
        // Please directly use func 'output' to output
        // the results into output buffer.
        // void output(string &key, vector<int>& value);
        while (!input->done()) {
            vector<int> v = input->value();
            sort(v.begin(), v.end());
            output("_", v);
            input->next();
        }
    }
};

class Node {
    public:
    int row, col, val;
    Node(int _r, int _c, int _v): row(_r), col(_c), val(_v){};
    bool operator < (const Node& obj) const {
        return val > obj.val;
    }
};

class SortIntegersReducer: public Reducer {
    public:
    void Reduce(string &key, vector<vector<int>>& input) {
        // Write your code here
        // Please directly use func 'output' to output
        // the results into output buffer.
        // void output(string &key, vector<int>& value);
        priority_queue<Node> pq;
        int k = input.size();
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            if (input[i].size() > 0) {
                pq.push(Node(i, 0, input[i][0]));
            }
        }
        while (!pq.empty()) {
            Node t = pq.top();
            int row = t.row;
            int col = t.col;
            int val = t.val;
            pq.pop();
            ans.push_back(val);
            if (++col < input[row].size()) {
                pq.push(Node(row, col, input[row][col]));
            }
        }
        output("_", ans);
    }
};
