package main
import (
    "bufio"
    "fmt"
    "log"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    reader.ReadString('\n')
    input, err := reader.ReadString('\n')
    if err != nil {
        log.Fatal(err)
    }
    var data []float64
    for _, nStr := range strings.Split(strings.TrimSpace(input)," ") {
        n, err := strconv.ParseFloat(nStr,64)
        if err != nil {
            log.Fatal(err)
        }
        data = append(data, n)
    }
    var out string
    for i, v := range data {
        if i == 0 {
            out += fmt.Sprintf("%.8f ", v)
        } else if i == len(data)-1 {
            out += fmt.Sprintf("%.8f", v)
        } else {
            out += fmt.Sprintf("%.8f ", (data[i-1]+v+data[i+1])/3)
        }
    }
    fmt.Println(out)
}
