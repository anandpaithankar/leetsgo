class MyStack {
    std::queue<int> _inStack;
    std::queue<int> _reserve;
    int _top;
    
public:
    /** Initialize your data structure here. */
    MyStack():_top(-1) {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        _top = x;
        _inStack.push(x);        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (empty()) {
            return -1;
        }
        
        while(_inStack.size() > 1) {
            auto v = _inStack.front();
            _inStack.pop();
            _reserve.push(v);
        }
        
        auto v = -1;
        if (_inStack.size() == 1) {
            v = _inStack.front();
            _inStack.pop();
            _top = -1;
        }
        
        assert(_inStack.empty());
        
        while(!_reserve.empty()) {
            _top = _reserve.front();
            _inStack.push(_top);
            _reserve.pop();
        }
        
        assert(_reserve.empty());
        
        return v;
    }
    
    /** Get the top element. */
    int top() {
        return (empty() == false ?_top : -1);
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return _inStack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */