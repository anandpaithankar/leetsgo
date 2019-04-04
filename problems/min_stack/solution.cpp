class MinStack {
    std::stack<int> _stack;
    std::stack<int> _min;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        _stack.push(x);
        if (_min.empty()) {
            _min.push(x);
        } else {
            if (x <= _min.top()) {
                _min.push(x);
            }
        }
    }
    
    void pop() {
        if (_stack.empty()) {
            return;
        }
        
        auto t = _stack.top();
        _stack.pop();
        if (t == _min.top()) {
            _min.pop();
        }        
    }
    
    int top() {
        return _stack.empty() ? -1 : _stack.top();
    }
    
    int getMin() {
        return _min.empty() ? -1 : _min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */