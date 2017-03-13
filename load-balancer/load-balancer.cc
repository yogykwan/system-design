class LoadBalancer {
public:
    LoadBalancer() {
        // Initialize your data structure here.
        ids.clear();
        id_index.clear();
    }

    // @param server_id add a new server to the cluster 
    // @return void
    void add(int server_id) {
        // Write your code here
        if (id_index.find(server_id) == id_index.end()) {
            id_index[server_id] = ids.size();
            ids.push_back(server_id);
        }
    }

    // @param server_id server_id remove a bad server from the cluster
    // @return void
    void remove(int server_id) {
        // Write your code here
        if (id_index.find(server_id) != id_index.end()) {
            int index = id_index[server_id];
            ids[index] = *(ids.end() - 1);
            ids.pop_back();
            id_index[ids[index]] = index;
            id_index.erase(server_id);
        }
    }

    // @return pick a server in the cluster randomly with equal probability
    int pick() {
        // Write your code here
        int index = rand() % ids.size();
        return ids[index];
    }
    
private:
    vector<int> ids;
    map<int, int> id_index;
};

