class MyHashSet {
    static const int SIZE = 1000;
    vector<list<int>> buckets;
    
    int hash(int key) { return key % SIZE; }
    
public:
    MyHashSet() : buckets(SIZE) {}
    
    void add(int key) {
        int h = hash(key);
        if (find(buckets[h].begin(), buckets[h].end(), key) == buckets[h].end())
            buckets[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        buckets[h].remove(key);
    }
    
    bool contains(int key) {
        int h = hash(key);
        return find(buckets[h].begin(), buckets[h].end(), key) != buckets[h].end();
    }
};