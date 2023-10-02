package main
import (
    "fmt"
    "strconv"
    "log"
)

func main() {
    var a, b string
    _, err := fmt.Scanln(&a, &b)
    if err != nil {
        log.Fatal(err)
    }
    fa, err := strconv.ParseInt(a,10,64)
    if err != nil {
        log.Fatal(err)
    }
    fb, err := strconv.ParseInt(b,10,64)
    if err != nil {
        log.Fatal(err)
    } // :)
    fmt.Println(fa*fb)
}
