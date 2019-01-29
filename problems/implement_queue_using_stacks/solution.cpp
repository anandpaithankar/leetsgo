class MyQueue {
    std::stack<int> _inStack;
	std::stack<int> _outStack;
    
    bool isEmpty(const std::stack<int>& stack) { return stack.empty(); }
	
	// move contents between stacks
	void moveContents(std::stack<int>& from, std::stack<int>& to) {
		while(!from.empty()) {
			to.push(from.top());
			from.pop();
		}						
	}
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (!isEmpty(_outStack)) {
	        moveContents(_outStack, _inStack);
	    }
    
        _inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
         moveContents(_inStack, _outStack);
        if (!isEmpty(_outStack)) {
            auto v = _outStack.top();
            _outStack.pop();
            return v;
        }
        return -1;
    }
    
    /** Get the front element. */
    int peek() {
        if (isEmpty(_outStack)){
            moveContents(_inStack, _outStack);
        }

        return _outStack.empty() ? -1 : _outStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return isEmpty(_inStack) && isEmpty(_outStack);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */