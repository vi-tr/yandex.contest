package main

import "fmt"

//--- cut here

func fill(maze [][]int) {
for x, row := range maze {
for y, v := range row {
    if v == -1 {
        for ox:=-1; ox<=1; ox++ {
        for oy:=-1; oy<=1; oy++ {
            if (x+ox >= 0) && (x+ox < len(maze)) &&
                (y+oy >= 0) && (y+oy < len(maze[x+ox])) &&
                maze[x+ox][y+oy] != -1 {
                        maze[x+ox][y+oy] += 1
            }
        } }
    }
} } }

//---

func main() {
    var rows, cols int
    fmt.Scanf("%d %d\n", &rows, &cols)
    
    // Создаём срез и заполняем его данными о расположении мин
    maze := make([][]int, rows, rows)
    for i := range maze {
        maze[i] = make([]int, cols, cols)
        for j := range maze[i] {
            fmt.Scanf("%d", &maze[i][j])
        }
    }
    
    // Заполняем игровое поле подсказками
    fill(maze)
    
    // Выводим на экран
    for _, row := range maze {
         for _, cell := range row {
             fmt.Printf("%3d", cell)
        }
        fmt.Println()
    }
}
