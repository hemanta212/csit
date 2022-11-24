package main

import "fmt"

type Node struct {
	item string
	next *Node
}

func main() {
	var n *Node
	push(&n, "first")
	push(&n, "second")
	fmt.Println(pop(&n))
	push(&n, "third")
	fmt.Println(pop(&n))
	fmt.Println(pop(&n))
	fmt.Println(pop(&n))
}

func push(node **Node, item string) {
	*node = &Node{item: item, next: *node}
}

func pop(node **Node) string {
	if *node == nil {
		return "Error: Empty stack"
	}
	n := *node
	popped := n.item
	*node = n.next
	return popped
}
