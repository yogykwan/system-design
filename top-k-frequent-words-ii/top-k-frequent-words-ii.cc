map<string, int> records;
class MyCmp {
    public:
    bool operator () (const string& a, const string &b) {
        int ca = records[a];
        int cb = records[b];
        if (ca != cb) return ca > cb;
        return a < b;
    }
};

class TopK {
    public:
    TopK(int k) {
        // initialize your data structure here
        this->k = k;
    }
    
    void add(string& word) {
        // Write your code here
        if (records.find(word) == records.end()) {
            records[word] = 1;
        } else {
            if (ans.find(word) != ans.end()) {
                ans.erase(word);
            }
            records[word] += 1;
        }
        ans.insert(word);
        if (ans.size() > k) {
            ans.erase(--ans.end());
        }
    }
    
    vector<string> topk() {
        // Write your code here
        vector<string> strs;
        for (set<string, MyCmp>::iterator it = ans.begin(); it != ans.end(); ++it) {
            strs.push_back(*it);
        }
        return strs;
    }
    
    private:
    set<string, MyCmp> ans;
    int k;
};
