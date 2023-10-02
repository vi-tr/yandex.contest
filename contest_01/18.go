package main
import (
    "fmt"
    "log"
    "math"
)

const alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

func otherAlg(x int, m []rune) string {
    var out = []int{0}
    for j:=0; j<x; j++ {
        out[0] += 1
        for i:=0; out[i] == 27; i++ {
            out[i] = 1
            if len(out)>=i+2 {
                out[i+1] += 1
            } else {
                out = append(out, 1)
            }
        }
    }
    
    outStr := ""
    for _, v := range out {
        outStr = string(m[v-1]) + outStr
    }
    return outStr
}

func main() {
    var x int
    m := []rune(alpha)
    _, err := fmt.Scanln(&x)
    if err != nil {
        log.Fatal(err)
    }

    w, out := x, ""
    for i:=math.Log(float64(x))/math.Log(27); i>=0; i-- {
        order := int(math.Pow(26,math.Floor(i)))
        if (w/order > 26) || (w/order < 1) {
            out = otherAlg(x, m) // my excuse: it was 3 AM
            break
        }
        out += string(m[w/order-1])
        w %= order
    }
    fmt.Println(out)
}
