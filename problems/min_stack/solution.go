type MinStack struct {
    reg []int
	max []int
    
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{}
}


func (st *MinStack) Push(val int)  {
    st.reg = append(st.reg, val)
	if len(st.max) == 0 || st.max[len(st.max)-1] >= val {
		st.max = append(st.max, val)
	}
}


func (st *MinStack) Pop()  {
    top := st.Top()
	st.reg = st.reg[:len(st.reg)-1]
	if top == st.max[len(st.max)-1] {
		st.max = st.max[:len(st.max)-1]
	}
    
}


func (st *MinStack) Top() int {
    return st.reg[len(st.reg)-1]
}


func (st *MinStack) GetMin() int {
    return st.max[len(st.max)-1]
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */