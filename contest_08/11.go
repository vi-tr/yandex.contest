package main
import "fmt"

type Matrix struct{
    data [][]int
}

// cut
func NewMatrix(rows, cols, value int) Matrix {
    result := Matrix{data: make([][]int, rows)}
    for y := range result.data {
        result.data[y] = make([]int, cols)
        for x := range result.data[y] {
            result.data[y][x] = value
        }
    }
    return result
}
func (m *Matrix) Rows() int { return len(m.data) }
func (m *Matrix) Cols() int { return len(m.data[0]) }
func (m *Matrix) Set(row, col, value int) { m.data[row][col] = value }
func (m *Matrix) Get(row, col int) int { return m.data[row][col] }
func (m *Matrix) AddRow(value int) {
    r := m.Rows()
    m.data = append(m.data, make([]int, r+1))
    for x := range m.data[r] {
        m.data[r][x] = value
    }
}
func (m *Matrix) AddCol(value int) {
    for y := range m.data {
        m.data[y] = append(m.data[y], value)
    }
}
func (m *Matrix) Convolution(core *Matrix) Matrix {
    rrows, rcols := m.Rows()-core.Rows()+1, m.Cols()-core.Cols()+1
    result := NewMatrix(rrows,rcols,0)
    for ry:=0;ry<rrows;ry++ { for rx:=0;rx<rcols;rx++ {
            sum := 0
            for y:=0;y<core.Rows();y++ { for x:=0;x<core.Cols();x++ {
                sum += m.data[ry+y][rx+x] * core.data[y][x]
            }}
            result.data[ry][rx] = sum
    }}
    return result
}
func (a *Matrix) Multiplication(b *Matrix) *Matrix {
    result := NewMatrix(a.Rows(), b.Cols(), 0)
    for ry:=0;ry<a.Rows();ry++ { for rx:=0;rx<b.Cols();rx++ {
        sum := 0
        for i:=0;i<a.Cols();i++ { sum += a.data[ry][i] * b.data[i][rx] }
        result.data[ry][rx] = sum
    }}

    return &result
}
func (m *Matrix) String() (result string) {
    for _,row := range m.data {
        for _,v := range row {
            result += fmt.Sprint(v) + " "
        }
        result += "\n"
    }
    return
}
// cut

func main() {
    var rowsFirst, colsFirst, firstInitVal,
        rowsCore, colsCore int
    
    fmt.Scan(&rowsFirst, &colsFirst, &firstInitVal)
    first := NewMatrix(rowsFirst, colsFirst, firstInitVal)
    for i := 0; i < first.Rows(); i++ {
        for j := 0; j < first.Cols(); j++ {
            var t int
            fmt.Scan(&t)
            first.Set(i, j, t)
        }
    }

    fmt.Scan(&rowsCore, &colsCore)
    core := NewMatrix(rowsCore, colsCore, 0)
    for i := 0; i < core.Rows(); i++ {
        for j := 0; j < core.Cols(); j++ {
            var t int
            fmt.Scan(&t)
            core.Set(i, j, t)
        }
    }
    
    conv := first.Convolution(&core)
    
    conv.AddRow(1)
    conv.AddCol(1)
    conv.AddCol(1)
    
    mult := conv.Multiplication(&first)
    
    fmt.Print(mult)
}
