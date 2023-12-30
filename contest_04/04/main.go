package main
import (
    "fmt"
    "encoding/csv"
    "os"
    "strings"
    "strconv"
    "sort"
)

type noTuplesInGoLol struct {
    name string
    age uint64
}

func main() {
    f, e := os.ReadFile("train.csv")
    if e != nil { panic(e) }
    ff := strings.NewReader(strings.ReplaceAll(string(f), "\r", "\n"))
    r := csv.NewReader(ff)
    t, e := r.ReadAll()
    if e != nil { panic(e) }

    var pclass string
    var age uint64
    var ans []noTuplesInGoLol
    fmt.Scanln(&pclass, &age)
    for _, v := range t {
        i, _ := strconv.ParseUint(v[5],10,64)
        if v[2] == pclass && v[4] == "female" && i > age {
            ans = append(ans, noTuplesInGoLol{v[3], i})
        }
    }
    sort.Slice(ans, func(i, j int) bool {
        if ans[i].age == ans[j].age {
            return ans[i].name < ans[j].name
        }
        return ans[i].age < ans[j].age
    })
    for _, v := range ans {
        fmt.Println(v.name)
    }
}
