class MyHashSet {
public:
    MyHashSet() {
        
    }
    vector<int>arr;
    void add(int key) {
        arr.push_back(key);
    }
    
    void remove(int key) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]==key){
                arr.erase(arr.begin()+i);
            }
        }
    }
    
    bool contains(int key) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]==key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */