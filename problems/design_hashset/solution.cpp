struct Node {
    int key;
    struct Node *next;
    Node(int k, Node* n=nullptr):key(k), next(n) {}
};


class MyHashSet {
    Node **_table;
    int _capacity;
    int _maxCapacity;
    
private:
    int getIndex(int key);
    int hashCode(int key);
    
    bool empty() { return (_capacity == 0); }
    
    Node *addToHead(Node *head, int key);
    Node *deleteNode(Node *head, int key);
    bool contains(Node *head, int key);
    
public:
    /** Initialize your data structure here. */
    MyHashSet():_maxCapacity(10000), _capacity(0) {
        _table = new Node*[_maxCapacity];
        for (int i = 0; i < _maxCapacity; i++) {
            _table[i] = nullptr;
        }
    }
    
    void add(int key) {
        if (_capacity == _maxCapacity) {
            return;
        }
        
        int index = getIndex(key);
        assert(index < _maxCapacity);
        auto entry = _table[index];
        
        if (contains(entry, key)) {
            return;
        }
        
        entry = addToHead(entry, key);
        assert(entry);
        _table[index] = entry;
        _capacity++;
    }
    
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
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if (empty()) {
            return false;
        }
        
        int index = getIndex(key);
        auto entry = _table[index];
        return contains(entry, key);
    }
};

int MyHashSet::getIndex(int key) {
    size_t code = hashCode(key);
    return (code % _maxCapacity);
}

int MyHashSet::hashCode(int key) {
    unsigned int hash = 5381;
    hash = ((hash << 5) + hash) + (key);
    return hash;
}

Node *MyHashSet::addToHead(Node *head, int key) {
    if (head == nullptr) {
        return new Node(key);
    }
    
    Node *t = head;
    return new Node(key, t);
}

Node *MyHashSet::deleteNode(Node *head, int key) {
    if (head == nullptr) {
        return head;
    }
    
    Node dummy(0, head);
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

bool MyHashSet::contains(Node *head, int key) {
    for (auto c = head; c != nullptr; c=c->next) {
        if (c->key == key) {
              return true;
        }
    }
    return false;
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */