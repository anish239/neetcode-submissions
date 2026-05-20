class MyHashMap {
    static const int SIZE = 1000;
    vector<list<pair<int,int>>> buckets;
    
    int hash(int key) { return key % SIZE; }
    
    list<pair<int,int>>::iterator find(int key) {
        int h = hash(key);
        for (auto it = buckets[h].begin(); it != buckets[h].end(); it++)
            if (it->first == key) return it;
        return buckets[h].end();
    }

public:
    MyHashMap() : buckets(SIZE) {}
    
    void put(int key, int value) {
        auto it = find(key);
        int h = hash(key);
        if (it != buckets[h].end())
            it->second = value;       // update existing
        else
            buckets[h].push_back({key, value});  // insert new
    }
    
    int get(int key) {
        auto it = find(key);
        int h = hash(key);
        return (it != buckets[h].end()) ? it->second : -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        auto it = find(key);
        if (it != buckets[h].end())
            buckets[h].erase(it);
    }
};