#include <iostream>
#include <tuple>

int** new_matrix(int rows, int cols, int value=0);
std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows=3, int ccols=3);
std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols);
std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value=1);
std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value=1);
void delete_matrix(int*** matrix, int rows);
void print(int** matrix, int rows, int cols);

int main(){
    int rows_first, cols_first, first_init_val,
        rows_core, cols_core;
        
    std::cin >> rows_first >> cols_first >> first_init_val;
    int** first = new_matrix(rows_first, cols_first, first_init_val);
    for(int i=0; i < rows_first; i++)
        for(int j=0; j < cols_first; j++)
            std::cin >> first[i][j];

    std::cin >> rows_core >> cols_core;
    int** core = new_matrix(rows_core, cols_core);
    for(int i=0; i < rows_core; i++)
        for(int j=0; j < cols_core; j++)
            std::cin >> core[i][j];
    
    auto [conv, rows_conv, cols_conv] = convolution(first, rows_first, cols_first, core);
    
    std::tie(rows_conv, cols_conv) = add_row(&conv, rows_conv, cols_conv);
    std::tie(rows_conv, cols_conv) = add_col(&conv, rows_conv, cols_conv);
    std::tie(rows_conv, cols_conv) = add_col(&conv, rows_conv, cols_conv);
    
    auto [mult, rows_mult, cols_mult] = multiplication(conv, rows_conv, cols_conv, first, rows_first, cols_first);
    
    print(mult, rows_mult, cols_mult);
    
    delete_matrix(&first, rows_first);
    delete_matrix(&conv, rows_conv);
    delete_matrix(&mult, rows_mult);
}

// cut
#include <cstdlib>

int** new_matrix(int rows, int cols, int value) {
    int** ptr = (int**)malloc(cols * sizeof(int*));
    for (int y=0;y<rows;y++) {
        ptr[y] = (int*)malloc(rows * sizeof(int));
        for (int x=0;x<cols;x++) ptr[y][x] = value;
    }
    return ptr;
}

std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows, int ccols) {
    int** result = new_matrix(crows, ccols);
    for (int ry=0;ry<=mrows-crows;ry++) for (int rx=0;rx<=mcols-ccols;rx++) {
        int sum = 0;
        for (int y=0;y<crows;y++) for (int x=0;x<ccols;x++)
            sum += matrix[ry+y][rx+x] * core[y][x];
        result[ry][rx] = sum;
    }

    return std::make_tuple(result, mrows-crows+1, mcols-ccols+1);
}
std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols) {
    int** result = new_matrix(arows, bcols);
    for (int ry=0;ry<arows;ry++) for (int rx=0;rx<bcols;rx++) {
        int sum = 0;
        for (int i=0;i<brows;i++) sum += a[ry][i] * b[i][rx];
        result[ry][rx] = sum;
    }

    return std::make_tuple(result, arows, bcols);
}
std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value) {
    *matrix = (int**)realloc(*matrix, (rows+1) * sizeof(int*));
    (*matrix)[rows] = (int*)malloc(cols * sizeof(int));
    for (int x=0;x<cols;x++) (*matrix)[rows][x]=value;
    return std::make_tuple(rows+1, cols);
}
std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value) {
    for (int y=0;y<rows;y++) {
        (*matrix)[y] = (int*)realloc((*matrix)[y], (cols+1) * sizeof(int));
        (*matrix)[y][cols] = value;
    }
    return std::make_tuple(rows, cols+1);
}
void delete_matrix(int*** matrix, int rows) {
    if (*matrix != nullptr) {
        for (int y=0;y<rows;y++) free((*matrix)[y]);
        free(*matrix);
        *matrix = nullptr;
    }
}
void print(int** matrix, int rows, int cols) {
    for (int y=0;y<rows;y++) {
        for (int x=0;x<cols;x++)
            std::cout << matrix[y][x] << " ";
        std::cout << std::endl;
    }
}
