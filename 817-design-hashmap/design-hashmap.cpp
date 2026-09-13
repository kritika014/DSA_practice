class MyHashMap {
public:
    MyHashMap() {}
    vector<vector<int>> arr;
    void put(int key, int value) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i][0] == key) {
                arr[i][1] = value; // key exists, update value
                return;
            }
        }
        arr.push_back({key, value});
    }

    int get(int key) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i][0] == key) {
                return arr[i][1];
            }
        }
        return -1;
    }

    void remove(int key) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i][0] == key) {
                arr.erase(arr.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */