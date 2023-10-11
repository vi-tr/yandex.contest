package main
import "fmt"

func main() {
    amount, target, n, smaller, bigger := 0, 0, 0, 0, 0
    fmt.Scanln(&amount, &target)

    pairs := make(map[int]bool)
    for i:=0; i<amount; i++ {
        fmt.Scan(&n)
        if n>=target {continue}
        if _, ok := pairs[n]; ok {
            if n <= target-n {
                    smaller,bigger = n,target-n
            } else {smaller,bigger = target-n,n}
            break
        } else {
            pairs[target-n] = true
        }
    }

    fmt.Println(smaller, bigger)
}
