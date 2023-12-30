package main

import (
    "fmt"
)

type Stack interface{
    empty() bool
    push(r rune)
    top() rune
    pop() rune
}

// cut
type SimpleStack struct { data *[]rune }
func NewSimpleStack() (r SimpleStack) { wtf := make([]rune,0); r.data = &wtf; return }
func (self SimpleStack) empty() bool { return len(*self.data)==0 }
func (self SimpleStack) push(r rune) { *self.data = append(*self.data, r) }
func (self SimpleStack) top() rune { return (*self.data)[len(*self.data)-1] }
func (self SimpleStack) pop() (r rune) {
    r = self.top()
    *self.data = (*self.data)[:len(*self.data)-1]
    return
}
// cut

func bracketValidator(stack Stack, str string) bool{
    mapping := map[rune]rune{
        ')': '(',
        ']': '[',
        '}': '{',
    }

    for _, char := range str {
        if char == '(' || char == '[' || char == '{' {
            stack.push(char)
        } else if char == ')' || char == ']' || char == '}' {
            if stack.empty() || stack.top() != mapping[char] {
                return false
            }
            stack.pop()
        }
    }

    return stack.empty()
}

func main() {
    var input string
    fmt.Scan(&input)
    fmt.Println(bracketValidator(NewSimpleStack(), input))
}
