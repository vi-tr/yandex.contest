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
    var data []int
    var cache []int
    for _, nStr := range strings.Split(strings.TrimSpace(input)," ") {
        n, err := strconv.Atoi(nStr)
        if err != nil {
            log.Fatal(err)
        }
        data = append(data, n)
        cache = append(cache, n)
    }
    for i:=len(cache)-2; i>=0; i-- {
        if cache[i] < cache[i+1] {
            cache[i] = cache[i+1]
        }
    }

    var ans int
    for i, _ := range data {
        if (i!=0) && (i!=len(data)-1) {
            if data[i-1]>data[i] {
                j:=data[i-1]
                for (j > cache[i]) {j--}
                if j > data[i] {
                    ans += j - data[i]
                    data[i]=j
                }
            }
        }
    }
    fmt.Println(ans)
}
