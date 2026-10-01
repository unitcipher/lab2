#include "Table.h"
#include <iostream>
#include <stdexcept>

Table::Table(int rows, int cols) : rows(rows), cols(cols) {
    if (rows <= 0 || cols <= 0)
        throw std::invalid_argument("Размеры таблицы должны быть положительными");
    data.assign(rows, std::vector<int>(cols, 0));
}

int  Table::get_value(int row, int col) const { return data[row][col]; }
void Table::set_value(int row, int col, int value) { data[row][col] = value; }
int  Table::n_rows() const { return rows; }
int  Table::n_cols() const { return cols; }

void Table::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j];
            if (j + 1 < cols) std::cout << " ";
        }
        std::cout << std::endl;
    }
}

double Table::average() const {
    long long sum = 0;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            sum += data[i][j];
    return static_cast<double>(sum) / (rows * cols);
}