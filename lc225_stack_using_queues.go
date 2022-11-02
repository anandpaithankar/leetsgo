package main

import (
	"container/list"
	"fmt"
)

type stack struct {
	q1 *list.List
	q2 *list.List
}

func (st *stack) Push(val int) {
	st.q2.PushBack(val)
	for st.q1.Len() != 0 {
		x := st.q1.Front()
		st.q2.PushBack(x.Value)
		st.q1.Remove(x)
	}
	st.q1, st.q2 = st.q2, st.q1
}

func (st *stack) Pop() {
	st.q1.Remove(st.q1.Front())
}

func (st *stack) Top() int {
	return st.q1.Front().Value.(int)
}

func (st *stack) Empty() bool {
	return st.q1.Len() == 0
}

func main() {
	st := stack{list.New(), list.New()}

	fmt.Println("Stack empty ", st.Empty())
	st.Push(1)
	st.Push(2)
	st.Push(3)

	fmt.Println("Stack top ", st.Top())

	st.Pop()
	fmt.Println("Stack top ", st.Top())
	st.Push(9)
	fmt.Println("Stack top ", st.Top())
	fmt.Println("Stack empty ", st.Empty())
}
