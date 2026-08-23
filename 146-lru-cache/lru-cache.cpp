class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int K, int V) {
            key = K;
            val = V;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int limit;
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* ansNode = mp[key];
        int ans = ansNode->val;
        delNode(ansNode);
        addNode(ansNode);
        return ans;
    }
    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }
    void delNode(Node* oldNode) {
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* oldNode = mp[key];
            delNode(oldNode);
            mp.erase(key);
            delete oldNode;
        }
        if (mp.size() == limit) {
            Node* lru = tail->prev; // CHANGED: cache pointer first
            mp.erase(lru->key);     // CHANGED: use cached pointer
            delNode(lru);           // CHANGED: use cached pointer
            delete lru;
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */