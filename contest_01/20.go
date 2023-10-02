package main
import (
    "fmt"
    "reflect"
    "log"
)

func main() {
    var a, b string
    _, err := fmt.Scanln(&a, &b)
    if err != nil {
        log.Fatal(err)
    }

    sa, sb := []rune(a), []rune(b)
    ma, mb := make(map[rune]int), make(map[rune]int)

    for _, v := range sa {
        if _, ok := ma[v]; ok {
            ma[v] += 1
        } else {
            ma[v] = 1
        }
    }
    for _, v := range sb {
        if _, ok := mb[v]; ok {
            mb[v] += 1
        } else {
            mb[v] = 1
        }
    }

    if reflect.DeepEqual(ma,mb) {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
