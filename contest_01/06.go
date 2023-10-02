package main
import (
    "fmt"
    "strings"
    "log"
)

func main() {
    var x int
    _, err := fmt.Scanln(&x)
    if err != nil {
        log.Fatal(err)
    }
    m := []int{5000, 1000, 500, 200, 100}
    var r []int
    for i, mv := range m {
        r = append(r, 0)
        for (x >= mv) {
            r[i] += 1
            x -= mv
        }
    }
    fmt.Println(strings.Trim(fmt.Sprintf("%v", r), "[]"))
}
