class LRUCache {
    typedef std::unordered_map<int, std::pair<std::list<int>::iterator, int>> Cache;
    
    Cache _cache; // <keys, {iterator, values}>
    std::list<int> _queue; // store keys
    size_t _maxCapacity;
    
    void moveToFront(int key, Cache::iterator &it) {
        _queue.erase(it->second.first);
        _queue.push_front(key);
        it->second.first = _queue.begin();
    }
    
public:
    LRUCache(int capacity) : _maxCapacity((size_t)capacity){
        
    }
    
    int get(int key) {
        auto it  = _cache.find(key);
        if (it == _cache.end()) {
            return -1;
        }
        
        moveToFront(key, it);
        return it->second.second;
    }
    
    void put(int key, int value) {
        auto it = _cache.find(key);
        if (it != _cache.end()) {
            moveToFront(key, it);   
            it->second.second = value;
        } else {
            if (_cache.size() == _maxCapacity) {
                _cache.erase(_queue.back());
                _queue.pop_back();
            }
            
            _queue.push_front(key); // move newer entry to the front.
            _cache[key] = {_queue.begin(), value};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */