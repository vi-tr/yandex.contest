package main
import (
    "fmt"
    "os"
    "encoding/json"
)

func main() {
    var uid int
    var ans int = 0
    fmt.Scanln(&uid)
    fh, err := os.Open("data.json")
    if err != nil { panic(err) }
    data := []struct {
        ProjectID  int `json:"project_id"`
        Tasks       []struct {
            UserID      int     `json:"user_id"`
            Completed   bool    `json:"completed"`
        }
    }{}
    err = json.NewDecoder(fh).Decode(&data)
    if err != nil { panic(err) }
    for _, project := range data {
        for _, v := range project.Tasks {
            if v.Completed && v.UserID == uid { ans += 1 }
        }
    }
    fmt.Println(ans)
}
