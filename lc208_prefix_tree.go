package main

type TreeNode struct {
	Val   rune
	Word  string
	Nodes [26]*TreeNode
}

func NewNode(val rune) *TreeNode {
	v := &TreeNode{}
	v.Val = val
	return v
}

type Trie struct {
	root *TreeNode
}

func Constructor() Trie {
	return Trie{}
}

func (this *Trie) Insert(word string) {
	current := this.root
	for _, c := range word {
		node := current.Nodes[c-'a']
		if node == nil {
			current.Nodes[c-'a'] = NewNode(c)
		}
		current = current.Nodes[c-'a']
	}
	current.Word = word
}

func (this *Trie) Search(word string) bool {
	current := this.root
	for _, c := range word {
		current = current.Nodes[c-'a']
		if current == nil {
			return false
		}
	}
	return current.Word == word
}

func (this *Trie) StartsWith(prefix string) bool {
	current := this.root
	for _, c := range prefix {
		current = current.Nodes[c-'a']
	}

	if current == nil {
		return false
	}
	return true
}
