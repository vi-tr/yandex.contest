package main
import (
    "fmt"
    "log"
)

func main() {
    var key = map[string]string {
        "НетНетНет": "Кот",
        "НетНетДа":  "Жираф",
        "НетДаНет":  "Курица",
        "НетДаДа":   "Страус",
        "ДаНетНет":  "Дельфин",
        "ДаНетДа":   "Плезиозавры",
        "ДаДаНет":   "Пингвин",
        "ДаДаДа":    "Утка",
    }
    var a,b,c string
    _, err := fmt.Scanln(&a,&b,&c)
    if err!=nil {
        log.Fatal(err)
    }
    fmt.Println(key[a+b+c])
}
