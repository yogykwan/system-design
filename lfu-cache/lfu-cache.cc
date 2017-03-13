class Node {
public:
    Node(int k = 0, int v = 0): key(k), value(v), cnt(0), next(nullptr) {} 
public:
    int key, value, cnt;
    Node *next;
};

class LFUCache {
public:
    // @param capacity, an integer
    LFUCache(int capacity) {
        // Write your code here
        cap = capacity;
        len = 0;
        root = new Node();
        key_pa.clear();
        cnt_last[0] = root;
    }

    void up(Node *pa) {
        Node *cur = pa->next;
        cur->cnt += 1;
        if (cnt_last[cur->cnt - 1] == cur) {
            if (pa->cnt == cur->cnt - 1) {
                cnt_last[pa->cnt] = pa;
            } else {
                cnt_last.erase(cur->cnt - 1);
            }
        }
        Node *pd;
        if (cur->next && cur->next->cnt <= cur->cnt) {
            if (cnt_last.find(cur->cnt) != cnt_last.end()) {
                pd = cnt_last[cur->cnt];
            } else {
                pd = cnt_last[cur->cnt - 1];
            }
            pa->next = cur->next;
            key_pa[pa->next->key] = pa;
            if (pd->next) {
                key_pa[pd->next->key] = cur;
            }
            cur->next = pd->next;
            pd->next = cur;
            key_pa[cur->key] = pd;
        }
        cnt_last[cur->cnt] = cur;
    }

    void push(Node *cur) {
        ++len;
        if (root->next) {
            key_pa[root->next->key] = cur;
        }
        cur->next = root->next;
        root->next = cur;
        key_pa[cur->key] = root;
    }

    void pop() {
        --len;
        Node *cur = root->next;
        key_pa.erase(cur->key);
        root->next = cur->next;
        if (root->next) {
            key_pa[root->next->key] = root;
        }
        delete cur;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // Write your code here
        if (key_pa.find(key) != key_pa.end()) {
            Node *pa = key_pa[key];
            pa->next->value = value;
            up(pa);
        } else {
            if (cap == len) {
                pop();
            }
            Node *cur = new Node(key, value);
            push(cur);
            up(root);
        }
    }

    // @return an integer
    int get(int key) {
        // Write your code here
        if (key_pa.find(key) != key_pa.end()) {
            Node *pa = key_pa[key];
            int ans = pa->next->value;
            up(pa);
            return ans;
        } else {
            return -1;
        }
    }

private:
    Node *root;
    int cap;
    int len;
    map<int, Node*> key_pa;
    map<int, Node*> cnt_last;
};

