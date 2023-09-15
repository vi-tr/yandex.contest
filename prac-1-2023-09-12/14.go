package main
import (
    "fmt"
    "strings"
    "log"
)

func main() {
    var row, col int
    _, err := fmt.Scanln(&row,&col)
    if err != nil {
        log.Fatal(err)
    }
    var w []int

    for i:=1; i<=col; i++ {
        w = append(w, i)
    }
    var title string = "    |"
    for _, n := range w {
        title += fmt.Sprintf("%4v",n)
    }
    fmt.Println(title)
    fmt.Println("   "+strings.Repeat("-",len(title)-3))
    for i:=1; i<=row; i++ {
        if i!=1 {
            for j:=1; j<=col; j++ {
                w[j-1] += j;
            }
        }
        var line string = fmt.Sprintf("%4v|", i)
        for _, n := range w {
            line += fmt.Sprintf("%4v", n)
        }
        fmt.Println(line)
    }
}
