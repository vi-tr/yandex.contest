package main
import (
    "fmt"
    "log"
)

func main() {
    var x, ans int
    _, err := fmt.Scanln(&x)
    if err != nil {
        log.Fatal(err)
    }
    for (x != 1) {
        ans += 1
        if x%2 == 0 {
            x /= 2
        } else {
            x = 3*x + 1
        }
    }
    fmt.Println(ans)
}
