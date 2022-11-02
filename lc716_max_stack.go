package main

import "fmt"

type maxStack struct {
	reg []int
	max []int
}

// (st.rStack.Peek().(int) <= st.minStack.Peek().(int)) -- min stack
func (st *maxStack) Push(val int) {
	st.reg = append(st.reg, val)
	if len(st.max) == 0 || st.max[len(st.max)-1] <= val {
		st.max = append(st.max, val)
	}
}

func (st *maxStack) Pop() {
	top := st.Top()
	st.reg = st.reg[:len(st.reg)-1]
	if top == st.max[len(st.max)-1] {
		st.max = st.max[:len(st.max)-1]
	}
}

func (st *maxStack) Top() int {
	return st.reg[len(st.reg)-1]
}

func (st *maxStack) Max() int {
	return st.max[len(st.max)-1]
}

func main() {
	arr := []int{-4, -2, -8, 0, 4}
	stack := maxStack{}
	for _, v := range arr {
		stack.Push(v)
	}

	fmt.Printf("top = %d , max = %d\n", stack.Top(), stack.Max())
	stack.Pop()
	fmt.Printf("top = %d , max = %d\n", stack.Top(), stack.Max())
	stack.Pop()
	fmt.Printf("top = %d , max = %d\n", stack.Top(), stack.Max())
	stack.Pop()
	fmt.Printf("top = %d , max = %d\n", stack.Top(), stack.Max())
	stack.Pop()
	fmt.Printf("top = %d , max = %d\n", stack.Top(), stack.Max())
}
