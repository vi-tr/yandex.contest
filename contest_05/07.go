package main

import "fmt"

type Queue []int

func (self *Queue) Push(x int) {
    *self = append(*self, x)
}

func (self *Queue) IsEmpty() bool {
    return len(*self) == 0
}

func (self *Queue) Pop() int {
    h := *self
    var el int
    l := len(h)
    el, *self = h[0], h[1:l]
    return el
}

func NewQueue() *Queue {
    return &Queue{}
}

// cut

type Water struct { temperature int }
type Teapot struct { water Water }

func NewWater(t int) Water {
    return Water{temperature: t}
}

func NewTeapot(w Water) Teapot {
    return Teapot{water: w}
}

func (self *Teapot) is_boiling() bool {
    return self.water.temperature >= 100
}

func (self *Teapot) heat_up(t int) {
    self.water.temperature += t
}

// cut

func main(){
    var temperature, count int
    fmt.Scan(&temperature, &count)

    heat := NewQueue()
    for i := 0; i < count; i++ {
        var t int
        fmt.Scan(&t)
        heat.Push(t)
    }

    water := NewWater(temperature)
    teapot := NewTeapot(water)
    
    for !teapot.is_boiling() {
        teapot.heat_up(heat.Pop())
    }
    
    for !heat.IsEmpty() {
        fmt.Print(heat.Pop(), " ")
    }
}
