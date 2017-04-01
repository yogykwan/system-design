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
class TopKFrequentWordsMapper: public Mapper {
public:
    void Map(Input<Document>* input) {
        // Write your code here
        // Please directly use func 'output' to output
        // the results into output buffer.
        // void output(string &key, int value);
        while (!input->done()) {
            Document d = input->value();
            string s = d.content, t;
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
                output(t, 1);
            }
            input->next();
        }
    }
};

class Pair {
public:
    Pair(string k, int c): key(k), cnt(c) {}
    bool operator<(const Pair &p) const{
        if (cnt != p.cnt) return cnt > p.cnt;
        return key < p.key;
    }
    
    string key;
    int cnt;
};

class TopKFrequentWordsReducer: public Reducer {
public:
    void setUp(int k) {
        // initialize your data structure here
        this->k = k;
    }
    
    void Reduce(string &key, Input<int>* input) {
        // Write your code here
        int ans = 0;
        while (!input->done()) {
            ans += input->value();
            input->next();
        }
        Pair tp = Pair(key, ans);
        pq.push(tp);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    void cleanUp() {
        // Please directly use func 'output' to output
        // the top k pairs <word, times> into output buffer.
        // void output(string &key, int &value);
        stack<Pair> ans;  // output should be ascending order
        while (!pq.empty()) {
            ans.push(pq.top());
            pq.pop();
        }
        while (!ans.empty()) {
            output(ans.top().key, ans.top().cnt);
            ans.pop();
        }
    }
private:
    int k;
    priority_queue<Pair> pq;
};
