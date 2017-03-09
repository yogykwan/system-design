class Node {
public:
    Node(int k=0, int v=0): key(k), value(v), next(nullptr) {}
    int key, value;
    Node *next;
};

class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        // write your code here
        cap = capacity;
        head = new Node();
        tail = head;
        key_pa.clear();
    }
    
    // @move the latest to the end of link
    void move(Node *pa) {
        if (pa->next == tail) return;
        Node *cur = pa->next;
        pa->next = cur->next;
        key_pa[cur->next->key] = pa;
        tail->next = cur;
        key_pa[cur->key] = tail;
        tail = cur;
        tail->next = nullptr;
    }
    
    // @return an integer
    int get(int key) {
        // write your code here
        if (key_pa.find(key) != key_pa.end()) {
            move(key_pa[key]);
            return tail->value;
        } else {
            return -1;
        }
    }
    
    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        if (key_pa.find(key) != key_pa.end()) {
            move(key_pa[key]);
            tail->value = value;
        } else {
            Node *cur = new Node(key, value);
            tail->next = cur;
            key_pa[key] = tail;
            tail = cur;
            if (key_pa.size() > cap) {
                key_pa.erase(head->next->key);
                head->next = head->next->next;
                key_pa[head->next->key] = head;
            }
        }
    }
    
private:
    int cap;
    map<int, Node *> key_pa;
    Node *head, *tail;
};
