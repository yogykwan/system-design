class RateLimiter {
    public:
    /**
     * @param timestamp the current timestamp
     * @param event the string to distinct different event
     * @param rate the format is [integer]/[s/m/h/d]
     * @param increment whether we should increase the counter
     * @return true or false to indicate the event is limited or not
     */
    bool isRatelimited(int timestamp, string& event, string& rate, bool increment) {
        // Write your code here
        stringstream ss;
        ss << rate;
        int limit;
        ss >> limit;
        int base = 1;
        switch(rate[rate.length() - 1]) {
            case 'd': base *= 24;
            case 'h': base *= 60;
            case 'm': base *= 60;
        }
        if (logs.find(event) == logs.end()) {
            logs[event] = vector<int>();
        }
        
        int seg = logs[event].end() - upper_bound(logs[event].begin(), logs[event].end(), timestamp - base);
        if (increment && seg < limit) {
            logs[event].push_back(timestamp);
        }
        return seg >= limit;
    }
    
    private:
    map<string, vector<int> > logs;
};
