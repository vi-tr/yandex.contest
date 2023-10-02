package main
import (
    "bufio"
    "fmt"
    "log"
    "os"
    "sort"
    "strings"
)

func main() {
    input, err := bufio.NewReader(os.Stdin).ReadString('\n')
    if err != nil {
        log.Fatal(err)
    }
    data := strings.Split(strings.TrimSpace(input)," ")
    occ := make(map[string]int)
    var out []string
    for i, v := range data {
        if _, ok := occ[v]; ok {
            occ[v] += 1
        } else {
            occ[v] = 1
        }
        if v == "end" {
            for k, v := range occ {
                if v>1 {
                    out = append(out, k)
                }
            }
            occ = make(map[string]int)
            sort.Strings(out)
            if i!=len(data)-1 {
                fmt.Printf("%s ", strings.Trim(fmt.Sprintf("%v",out),"[]"))
            } else {
                fmt.Printf(strings.Trim(fmt.Sprintf("%v",out),"[]"))
            }
            out = nil
            break
        }
    }
}
