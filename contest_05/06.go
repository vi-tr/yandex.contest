package main
import (
    "fmt"
    "math/rand"
)

// cut

type Cat struct {
    status bool
}

func (self Cat) is_alive() bool {
    return self.status
}

type Box struct {
    opened bool
    inside Cat
}

func (self Box) open() Cat {
    if !self.opened {
        self.inside = Cat{status: rand.Float32() >= float32(0.5)}
        self.opened = true
    }
    return self.inside
}

// cut

func main() {
    var box Box
    cat := box.open()
    if cat.is_alive() {
        fmt.Print("alive")
    } else {
        fmt.Print("dead")
    }
}
