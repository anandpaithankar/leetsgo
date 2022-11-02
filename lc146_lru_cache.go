package main

import "container/list"

type Value struct {
	E *list.Element
	V int
}

type LRUCache struct {
	Cache       map[int]*Value
	Queue       *list.List // store keys
	MaxCapacity int
}

func Constructor(capacity int) *LRUCache {
	return &LRUCache{
		Cache:       make(map[int]*Value, capacity),
		Queue:       list.New(),
		MaxCapacity: capacity,
	}
}

func (this *LRUCache) Get(key int) int {
	var v *Value
	var ok bool

	if v, ok = this.Cache[key]; !ok {
		return -1
	}

	this.Queue.MoveToFront(v.E)
	return v.V
}

func (this *LRUCache) Put(key, value int) {
	var v *Value
	var ok bool

	if v, ok = this.Cache[key]; ok {
		this.Queue.MoveToFront(v.E)
		v.V = value
		return
	}

	if len(this.Cache) == this.MaxCapacity {
		delete(this.Cache, this.Queue.Back().Value.(int))
		this.Queue.Remove(this.Queue.Back())
	}

	this.Queue.PushFront(key)
	this.Cache[key] = &Value{E: this.Queue.Front(), V: value}
}
