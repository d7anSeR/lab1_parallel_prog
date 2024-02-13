#include <iostream>
#include <fstream>
#include <sstream>

int** readMatrix(const char* file_name) {
    std::ifstream file;
    file.open(file_name);
    int rows = 0;
    int cols = 0;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        int current_cols = 0;

        while (std::getline(ss, cell, ',')) {
            current_cols++;
        }

        if (current_cols > cols) {
            cols = current_cols;
        }

        rows++;
    }

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    file.clear();
    file.seekg(0, std::ios::beg);

    int row_index = 0;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        int col_index = 0;

        while (std::getline(ss, cell, ',')) {
            matrix[row_index][col_index] = std::stoi(cell);
            col_index++;
        }

        row_index++;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return matrix;
}
void clearMemory(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    int **matrix = readMatrix("C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_500.csv");
    int rows = 500;
    clearMemory(matrix, rows);

    int**matrix = readMatrix("C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_1000.csv");
    rows = 1000;
    clearMemory(matrix, rows);

    int** matrix = readMatrix("C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_1500.csv");
    rows = 2500;
    clearMemory(matrix, rows);

    int** matrix = readMatrix("C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_2000.csv");
    rows = 2000;
    clearMemory(matrix, rows);
}
