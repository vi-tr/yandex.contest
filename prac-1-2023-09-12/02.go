package main
import (
    "fmt"
    "math"
)

func main() {
    var daysInYear, oakProduces, poplarProduces float64 = 365, 20, 32
    var humanConsumes float64 = 0.5*daysInYear
    fmt.Println(humanConsumes, math.Ceil(humanConsumes/poplarProduces), math.Ceil(humanConsumes/oakProduces))
}
