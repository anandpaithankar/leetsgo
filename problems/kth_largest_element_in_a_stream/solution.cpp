class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> _pq; // min heap
    int _k;
    
public:
    KthLargest(int k, const vector<int>& nums):_k(k) {
        for (auto n: nums) {
            _pq.push(n);
            if (_pq.size() > k) {
                _pq.pop();
            }
        }
    }
    
    int add(int val) {
        _pq.push(val);
        if (_pq.size() > _k) {
            _pq.pop();
        }
        return _pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */