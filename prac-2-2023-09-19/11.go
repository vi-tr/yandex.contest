package main
import "fmt"

const rows int = 9
const cols int = 9

//--- cut here

func bade(collection []int) bool {
    var mem [10]bool
    //fmt.Printf("Check: ")
    for _, v := range collection {
        if v == 0 {
            return true
        }
        if mem[v] {
            //fmt.Printf("\nEPIC FAIL\n")
            return true
        } else {
            mem[v] = true
        }
        //fmt.Printf("%v",v)
    }
    //fmt.Printf("\n")
    return false
}

func isValidSudoku(board [9][9]int) bool {
    // columns
    for y:=0; y<9; y++ {
        if bade(board[y][:]) { return false }
    }
    // rows
    for y:=0; y<9; y++ {
        var tmp []int
        for x:=0; x<9; x++ {
            tmp = append(tmp, board[x][y])
        }
        if bade(tmp) { return false }
    }
    // squares
    for s:=0; s<9; s++ {
        var tmp []int
        for y:=int(s/3)*3; y<int(s/3)*3+3; y++ {
            for x:=int(s%3)*3; x<int(s%3)*3+3; x++ {
                //fmt.Printf("Added coordinate: %v, %v\n", x, y)
                tmp = append(tmp, board[x][y])
            }
        }
        if bade(tmp) { return false }
    }

    return true
}

//---

func main() {
    var bord [rows][cols]int
    
    for row:=0; row < rows; row++ {
        for col:=0; col < cols; col++ {
            fmt.Scanf("%c", &bord[row][col])  // Считываем один символ
            bord[row][col] -= '0'  // Чтобы из ASCII кода символа получить цифру
        }
        fmt.Scanf("\n")
    }
    
    if isValidSudoku(bord){
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
