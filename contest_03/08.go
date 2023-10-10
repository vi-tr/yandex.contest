package main
import "fmt"

func main() {
    var amount int
    fmt.Scan(&amount)

    occ := make(map[string]int)
    for i:=0; i<amount; i++ {
        var temp string
        fmt.Scan(&temp)
        if _, ok := occ[temp]; ok {
            delete(occ, temp)
        } else {
            occ[temp] = 1
        }
    }

    for k := range occ {
        fmt.Println(k)
    }
}
