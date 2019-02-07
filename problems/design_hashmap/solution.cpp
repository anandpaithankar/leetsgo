
struct Node {
    int key, value;
    struct Node *next;
    Node(int k, int v, Node* n=nullptr):key(k), value(v), next(n) {}
};

class MyHashMap {
    
    Node **_table;
    int _capacity;
    int _maxCapacity;
    
private:
    int getIndex(int key);
    int hashCode(int key);
    
    bool empty() { return (_capacity == 0); }
    
    Node *addToHead(Node *head, int key, int val);
    bool updateIfExists(Node *head, int key, int val);
    Node *deleteNode(Node *head, int key);
    
public:
    /** Initialize your data structure here. */
    MyHashMap():_maxCapacity(10000), _capacity(0) {
        _table = new Node*[_maxCapacity];
        for (int i = 0; i < _maxCapacity; i++) {
            _table[i] = nullptr;
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        if (_capacity == _maxCapacity) {
            return;
        }
        
        int index = getIndex(key);
        assert(index < _maxCapacity);
        auto entry = _table[index];
        
        if (updateIfExists(entry, key, value)) {
            return;
        }
        
        
        entry = addToHead(entry, key, value);
        assert(entry);
        _table[index] = entry;
        _capacity++;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (empty()) {
            return -1;
        }
        
        int index = getIndex(key);
        auto entry = _table[index];
        for (auto c = entry; c != nullptr; c=c->next) {
            if (c->key == key) {
                return c->value;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (empty()) {
            return;
        }
        
        int index = getIndex(key);
        auto entry = _table[index];
        if (entry != nullptr) {
            _table[index] = deleteNode(entry, key);
            if (_table[index] == nullptr) {
                _capacity--;
            }
        }
    }
};

int MyHashMap::getIndex(int key) {
    size_t code = hashCode(key);
    return (code % _maxCapacity);
}

int MyHashMap::hashCode(int key) {
    unsigned int hash = 5381;
    hash = ((hash << 5) + hash) + (key);
    return hash;
}
 
Node *MyHashMap::addToHead(Node *head, int key, int val) {
    if (head == nullptr) {
        return new Node(key, val);
    }
    
    Node *t = head;
    return new Node(key, val, t);    
}

bool MyHashMap::updateIfExists(Node *head, int key, int val) {
    if (head == nullptr) {
        return false;
    }
    
    for (auto c = head; c != nullptr; c = c->next) {
        if (c->key == key) {
            c->value = val;
            return true;
        }
    }
    return false;
}

Node *MyHashMap::deleteNode(Node *head, int key) {
    if (head == nullptr) {
        return head;
    }
    
    Node dummy(0,0, head);
    Node *prev = &dummy;
    for (Node *c = dummy.next; c != nullptr; prev = c, c = c->next) {
        if (c->key == key) {
            prev->next = c->next;
            delete c;
            break;
        }
    }
    
    return dummy.next;
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */