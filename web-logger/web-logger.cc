class WebLogger {
    public:
    WebLogger() {
        // initialize your data structure here.
    }
    
    void pop_hits(int ts) {
        ts -= 299;
        while (!hits.empty() && hits.front() < ts) {
            hits.pop();
        }
    }
    
    /**
     * @param timestamp an integer
     * @return void
     */
    void hit(int timestamp) {
        // Write your code here
        hits.push(timestamp);
        pop_hits(timestamp);
    }
    
    /**
     * @param timestamp an integer
     * @return an integer
     */
    int get_hit_count_in_last_5_minutes(int timestamp) {
        // Write your code here
        pop_hits(timestamp);
        return hits.size();
    }
    
    private:
    queue<int> hits;
};
