package hash_table

import (
	"hash/fnv"
)

const size = 100

type HT struct {
	node []*Node
}

type Node struct {
	key   string
	value string
	next  *Node
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
	current := ht.node[index]

	for current != nil {
		if current.key == key {
			return current.value
		}
		current = current.next
	}

	return ""
}

func (ht *HT) Set(key, value string) {
	index := ht.hashFunction(key)
	newNode := &Node{key, value, nil}
	newNode.next = ht.node[index]
	ht.node[index] = newNode
}