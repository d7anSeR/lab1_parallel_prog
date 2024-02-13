#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

void writeMatrix(int** matrix, int rows,const char* filename) {
    std::ofstream file(filename);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            file << matrix[i][j];
            if (j < rows - 1) {
                file << ",";
            }
        }
        if (i < rows - 1) {
            file << std::endl;
        }
    }
    file.close();
}

void writeTime(int** res_time, int rows, const char* filename) {
    std::ofstream file(filename);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            file << res_time[i][j];
            if (j < rows - 1) {
                file << ",";
            }
        }
        if (i < rows - 1) {
            file << std::endl;
        }
    }
    file.close();
}

int** readMatrix(const char* file_name) {
    std::ifstream file;
    file.open(file_name);
    int rows = 0;

    std::string line;
    while (std::getline(file, line)) {
      rows++;
    }

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[rows];
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
    return matrix;
}
//void clearMemory(int** matrix, int rows) {
//    for (int i = 0; i < rows; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//}
int** mulMatrix(int** matrix, int rows) {
    int** matrix_new = new int* [rows];
    for (int i = 0, int l = 0; i < rows; i++) {
        int count = 0;
        while (count < rows) {
            int sum = 0;
            for (int j = 0; j < rows; j++) {
                sum += (matrix[i][j] * matrix[j][count]);
            }
            matrix_new[i][count] = sum;
            count++;
        }
        
    }
    return matrix_new;
}
int fixTime(int** matrix, int rows, const char* file_name_res) {
    int start = clock();
    int** matrix_new = mulMatrix(matrix, rows);
    int end = clock();
    writeMatrix(matrix_new, rows, file_name_res);
    return (end - start);
}
int main()
{
    int **matrix = readMatrix("C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_500.csv");
    int rows = 500;
    int count_op = rows;
    int** matrix_time = new int* [count_op];
    for (int i = 0; i < count_op; i++) {
        int time_res = fixTime(matrix, rows, "C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_res_500.csv");
        matrix_time[0][i] = time_res;
    }
    writeMatrix(matrix_time, count_op, "C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_time_500.csv");
   /* clearMemory(matrix, rows);
    clearMemory(matrix_time, count_op);*/

    //matrix = readMatrix("C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_1000.csv");
    //rows = 1000;
    //count_op = rows;
    //matrix_time = new int* [count_op];
    //for (int i = 0; i < count_op; i++) {
    //    int time_res = fixTime(matrix, rows, "C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_res_1000.csv");
    //    matrix_time[1][i] = time_res;
    //}
    //writeMatrix(matrix_time, count_op, "C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_time_1000.csv");
    //clearMemory(matrix, rows);
    //clearMemory(matrix_time, count_op);

    //matrix = readMatrix("C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_1500.csv");
    //rows = 1500;
    //count_op = rows;
    //matrix_time = new int* [count_op];
    //for (int i = 0; i < count_op; i++) {
    //    int time_res = fixTime(matrix, rows, "C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_res_1500.csv");
    //    matrix_time[2][i] = time_res;
    //}
    //writeMatrix(matrix_time, count_op, "C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_time_1500.csv");
    //clearMemory(matrix, rows);
    //clearMemory(matrix_time, count_op);

    //matrix = readMatrix("C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_2000.csv");
    //rows = 2000;
    //count_op = rows;
    //matrix_time = new int* [count_op];
    //for (int i = 0; i < count_op; i++) {
    //    int time_res = fixTime(matrix, rows, "C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_res_2000.csv");
    //    matrix_time[3][i] = time_res;
    //}
    //writeMatrix(matrix_time, count_op, "C:\\Users\\Professional\\.vscode\\lab1_parallel_prog\\lab1_parallel_prog\\matrix_time_2000.csv");
    //clearMemory(matrix, rows);
    //clearMemory(matrix_time, count_op);
}
