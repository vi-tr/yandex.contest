package main
import (
    "fmt"
    "log"
)

func main() {
    var a,b,c int
    _, err := fmt.Scanln(&a, &b, &c)
    if err != nil {
        log.Fatal(err)
    }
    if a>b {
        if a>c {
            fmt.Println(a)
        } else {
            fmt.Println(c)
        }
    } else {
        if b>c {
            fmt.Println(b)
        } else {
            fmt.Println(c)
        }
    }
}
