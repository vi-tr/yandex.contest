package main
import (
    "bufio"
    "fmt"
    "os"
)

//--- cut here

import "strconv"

func isLucky(input string) bool {
    list := []rune(input)
    var intlist []int
    for _, v := range list {
        n, err := strconv.Atoi(string(v))
        if err != nil { fmt.Errorf("%s", err) }
        intlist = append(intlist, n)
    }
    return (intlist[0]+intlist[1]+intlist[2]) == (intlist[3]+intlist[4]+intlist[5])
}

//---

func main() {
    number, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isLucky( number[:len(number)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
