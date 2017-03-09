class Node {
public:
    Node(): ip(""), timestamp(0), next(nullptr) {}
    Node(string &i, int t): ip(i), timestamp(t), next(nullptr) {}
    
public:
    string ip;
    int timestamp;
    Node* next;
};

class HeartBeat {
public:
    HeartBeat() {
        // initialize your data structure here.
        root = new Node();
        key_pa.clear();
    }

    // @param slaves_ip_list a list of slaves'ip addresses
    // @param k an integer
    // @return void
    void initialize(vector<string>& slaves_ip_list, int k) {
        // Write your code here
        rtt = k * 2;
        Node *pa = root;
        for (auto &ip : slaves_ip_list) {
            Node *cur = new Node(ip, 0);
            key_pa[ip] = pa;
            pa->next = cur;
            pa = cur;
        }
        tail = pa;
    }

    // @param timestamp current timestamp in seconds
    // @param slave_ip the ip address of the slave server
    // @return nothing
    void ping(int timestamp, string& slave_ip) {
        // Write your code here
        if (key_pa.find(slave_ip) != key_pa.end()) {
            Node *pa = key_pa[slave_ip];
            Node *cur = pa->next;
            cur->timestamp = timestamp;
            if (cur == tail) return;
            pa->next = cur->next;
            key_pa[cur->next->ip] = pa;
            tail->next = cur;
            key_pa[slave_ip] = tail;
            tail = cur;
            tail->next = nullptr;
        }
    }

    // @param timestamp current timestamp in seconds
    // @return a list of slaves'ip addresses that died
    vector<string> getDiedSlaves(int timestamp) {
        // Write your code here
        vector<string> ans;
        Node *pa = root->next;
        while (pa != nullptr) {
            if (pa->timestamp <= timestamp - rtt) {
                ans.push_back(pa->ip);
                pa = pa->next;
            } else break;
        }
        return ans;
    }

private:
    int rtt;
    Node *root, *tail;
    map<string, Node *> key_pa;
};

