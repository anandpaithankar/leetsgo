type MyStack struct {
    q1 *list.List
	q2 *list.List
    
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{list.New(), list.New()}
}


/** Push element x onto stack. */
func (st *MyStack) Push(val int)  {
    st.q2.PushBack(val)
	for st.q1.Len() != 0 {
		x := st.q1.Front()
		st.q2.PushBack(x.Value)
		st.q1.Remove(x)
	}
	st.q1, st.q2 = st.q2, st.q1
}


/** Removes the element on top of the stack and returns that element. */
func (st *MyStack) Pop() int {
    x := st.q1.Front().Value.(int)
    st.q1.Remove(st.q1.Front())
    return x
}


/** Get the top element. */
func (st *MyStack) Top() int {
    return st.q1.Front().Value.(int)
}


/** Returns whether the stack is empty. */
func (st *MyStack) Empty() bool {
    return st.q1.Len() == 0
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */