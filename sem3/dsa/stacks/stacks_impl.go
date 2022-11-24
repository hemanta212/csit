package main

import "fmt"

type Stack struct {
	data []string
}

func main() {
	s := Stack{}
	s.push("aloha")
	s.push("hello")
	fmt.Println(s.pop())
	fmt.Println(s)
}

func (s *Stack) push(item string) {
	s.data = append(s.data, item)
}

func (s *Stack) pop() string {
	fmt.Println(s.data)
	last_index := len(s.data) - 1
	item := s.data[last_index]
	s.data = s.data[:last_index]
	return item
}
