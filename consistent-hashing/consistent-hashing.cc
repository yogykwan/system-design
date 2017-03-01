class Solution {
public:
    /**
     * @param n a positive integer
     * @return n x 3 matrix
     */

    vector<vector<int>> consistentHashing(int n) {
        // Write your code here
        typedef pair<int, int> pii;
        int total = 360;
        vector<pii> segments(total);
        priority_queue<pii> pq;
        pq.push(make_pair(total, 0));
        segments[0].first = 0;
        segments[0].second = total - 1;
        for (int i = 1; i < n; ++i) {
            int id = -pq.top().second;
            pq.pop();
            segments[i].second = segments[id].second;
            segments[id].second = (segments[id].first+segments[id].second) >> 1;
            segments[i].first = segments[id].second + 1;
            pq.push(make_pair(segments[i].second - segments[i].first + 1, -i));
            pq.push(make_pair(segments[id].second - segments[id].first + 1, -id));
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            int id = -pq.top().second;
            pq.pop();
            ans.push_back(vector<int>{segments[id].first, segments[id].second, id + 1});
        }
        return ans;
    }
};

