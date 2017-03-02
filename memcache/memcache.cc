class Memcache {
public:
    Memcache() {
        // initialize your data structure here.
        items.clear();
    }
    
    int get(int curtTime, int key) {
        // Write your code here
        if (items.find(key) != items.end()) {
            if (items[key].second == -1 || items[key].second> curtTime) {
                return items[key].first;
            } else {
                items.erase(key);
            }
        }
        return INF;
    }
    
    void set(int curtTime, int key, int value, int ttl) {
        // Write your code here
        if (ttl == 0) {
            items[key] = make_pair(value, -1);
        } else {
            items[key] = make_pair(value, curtTime + ttl);
        }
    }
    
    void del(int curtTime, int key) {
        // Write your code here
        if (items.find(key) != items.end()) {
            items.erase(key);
        }
    }
    
    int incr(int curtTime, int key, int delta) {
        // Write your code here
        if (items.find(key) != items.end()) {
            if (items[key].second == -1 || items[key].second> curtTime) {
                return items[key].first += delta;
            } else {
                items.erase(key);
            }
        }
        return INF;
    }
    
    int decr(int curtTime, int key, int delta) {
        // Write your code here
        if (items.find(key) != items.end()) {
            if (items[key].second == -1 || items[key].second> curtTime) {
                return items[key].first -= delta;
            } else {
                items.erase(key);
            }
        }
        return INF;
    }
    
private:
    map<int, pair<int, int>> items;
    const int INF = 2147483647;
};
