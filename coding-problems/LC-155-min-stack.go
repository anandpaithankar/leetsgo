package main

import (
	"errors"
	"fmt"

	"github.com/golang-collections/collections/stack"
)

// Min stack
type minStack struct {
	rStack   *stack.Stack
	minStack *stack.Stack
}

func (st *minStack) Push(val int) {
	st.rStack.Push(val)

	if st.minStack.Len() == 0 ||
		(st.rStack.Peek().(int) <= st.minStack.Peek().(int)) {
		st.minStack.Push(val)
	}
}

func (st *minStack) Pop() error {
	if st.rStack.Len() != 0 {
		top := st.rStack.Peek().(int)
		if top == st.minStack.Peek().(int) {
			st.minStack.Pop()
		}
		st.rStack.Pop()
		return nil
	}
	return errors.New("empty stack")
}

func (st *minStack) Top() (int, error) {
	if st.rStack.Len() != 0 {
		return st.rStack.Peek().(int), nil
	}
	return -1, nil
}

func (st *minStack) Min() (int, error) {
	if st.minStack.Len() != 0 {
		return st.minStack.Peek().(int), nil
	}
	return -1, errors.New("stack is empty")
}

func main() {

	m := minStack{stack.New(), stack.New()}

	values := []int{12, 1, 5, -1, 2, 0, 6}
	for _, val := range values {
		m.Push(val)
	}

	v, e := m.Top()
	fmt.Printf("min stack top %v, %v\n", v, e)
	v, e = m.Min()
	fmt.Printf("min stack min %v, error %v\n", v, e)
	m.Pop()
	m.Pop()
	m.Pop()

	m.Pop()
	v, e = m.Top()
	fmt.Printf("min stack top %v, %v\n", v, e)
	v, e = m.Min()
	fmt.Printf("min stack min %v, error %v\n", v, e)
}
