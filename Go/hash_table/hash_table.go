package hash_table

import (
	"hash/fnv"
)

const size = 100

type HT struct {
	Node []*Node
}

type Node struct {
	Key   string
	Value string
	Next  *Node
}

func NewHT() *HT {
	node := make([]*Node, size)
	return &HT{node}
}

func (ht *HT) hashFunction(key string) uint32 {
	h := fnv.New32a()
	h.Write([]byte(key))
	return h.Sum32() % uint32(size)
}

func (ht *HT) Get(key string) string {
	index := ht.hashFunction(key)
	current := ht.Node[index]

	for current != nil {
		if current.Key == key {
			return current.Value
		}
		current = current.Next
	}

	return ""
}

func (ht *HT) Set(key, value string) {
	index := ht.hashFunction(key)
	newNode := &Node{key, value, nil}
	newNode.Next = ht.Node[index]
	ht.Node[index] = newNode
}

