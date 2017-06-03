class Solution {
    public:
    /**
     * @param words an array of string
     * @param k an integer
     * @return an array of string
     */
    vector<string> topKFrequentWords(vector<string>& words, int k) {
        // Write your code here
        map<string, int> mmp;
        for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
            mmp[*it] = mmp[*it] + 1;
        }
        
        vector<pair<int, string> > ans;
        for (map<string, int>::iterator it = mmp.begin(); it != mmp.end(); ++it) {
            ans.push_back(make_pair(-it->second, it->first));
        }
        sort(ans.begin(), ans.end());
        
        k = min(k, (int)ans.size());
        vector<string> strs;
        for (int i = 0; i < k; ++i) {
            strs.push_back(ans[i].second);
        }
        return strs;
    }
};
