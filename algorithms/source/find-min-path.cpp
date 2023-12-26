
#include <iostream>
#include <vector>
#include <unordered_map>

// See https://coderun.yandex.ru/problem/cheapest-way/description?currentPage=1&pageSize=10&rowNumber=2
// Original description:
// В каждой клетке прямоугольной таблицы N×M записано некоторое число. Изначально игрок находится в левой верхней клетке.
// За один ход ему разрешается перемещаться в соседнюю клетку либо вправо, либо вниз (влево и вверх перемещаться запрещено).
// При проходе через клетку с игрока берут столько килограммов еды, какое число записано в этой клетке (еду берут также за первую и последнюю клетки его пути).
// Требуется найти минимальный вес еды в килограммах, отдав которую игрок может попасть в правый нижний угол.

// Max value per cell is 100.

using namespace std;

using SourceData = std::vector<vector<int>>;

// Helper structure to represent 2d array.
struct Array2D {
    
    SourceData data;
    int rows;
    int cols;
    
    Array2D(const SourceData& data, int rows, int cols) : data(data), rows(rows), cols(cols) {
        
    }
    
    int& operator()(int i, int j) {
        
        return data[i][j];
    }
    
    int operator()(int i, int j) const {
        
        return data[i][j];
    }
    
    int elems() const { return rows*cols; }
};

// To test 2d array.
void test_2ddata() {
    SourceData source = {{1, 2, 3}, {4, 5, 6}};
    Array2D arr(source, 2, 3);
    std::cout << "Array2D check: " << (arr(0, 0) == 1 ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Array2D check: " << (arr(1, 2) == 6 ? "PASSED" : "FAILED") << std::endl;
}

// Algorithm - v1, helper. Recursive without memo.
// Last parameter is an iterator which counts number of recursive calls.
// Go from bottom right cell to left top cell recursively.
int find_min_helper(const Array2D& data, int i, int j, int& it) {
    
    ++it;
    
    if (i < 0 || j < 0) return 101;

    int left_min = find_min_helper(data, i, j - 1, it);
    int top_min = find_min_helper(data, i - 1, j, it);
    
    int min = std::min(left_min, top_min);
    if (min == 101) return data(i, j);
    return min + data(i, j);
}

// Algorithm - v2, helper. Recursive.
// Last parameter is an iterator which counts number of recursive calls.
// Go from left top cell to right bottom cell.
int find_min_helper2(const Array2D& data, int i, int j, int& it) {
    
    ++it;
    
    if (i > data.rows - 1) return 101;
    if (j > data.cols - 1) return 101;

    int right_min = find_min_helper2(data, i, j + 1, it);
    int bottom_min = find_min_helper2(data, i + 1, j, it);
    
    int min = std::min(right_min, bottom_min);
    if (min == 101) return data(i, j);
    return min + data(i, j);
}

// Algorithm - v3, helper. Recursivewith a memo.
// Last parameter is an iterator which counts number of recursive calls.
// Go from bottom right cell to left top cell recursively.
int find_min_helper2_memo(const Array2D& data, int i, int j, std::unordered_map<int, int>& memo, int& it) {
    
    ++it;
    
    if (i > data.rows - 1) return 101;
    if (j > data.cols - 1) return 101;
    
    int right_min_cached = 101;
    if (memo.contains(i * data.cols + j + 1)) {
        right_min_cached = memo[i*data.cols + j + 1];
    }
    
    int bottom_min_cached = 101;
    if (memo.contains((i + 1)*data.cols + j)) {
        bottom_min_cached = memo[(i + 1)*data.cols + j];
    }

    int right_min = right_min_cached == 101 ? find_min_helper2_memo(data, i, j + 1, memo, it) : right_min_cached;
    int bottom_min = bottom_min_cached == 101 ? find_min_helper2_memo(data, i + 1, j, memo, it) : bottom_min_cached;
    if (right_min != 101) {
        memo.insert({i*data.cols + j + 1, right_min});
    }
    
    if (bottom_min != 101) {
        memo.insert({(i + 1)*data.cols + j, bottom_min});
    }
    
    int min = std::min(right_min, bottom_min);
    if (min == 101) return data(i, j);
    return min + data(i, j);
}

// Root function. Choose correct helper to define algorithm strategy.
int find_min(const Array2D& data, int& iterations) {
    // return find_min_helper(data, data.rows - 1, data.cols - 1, iterations);
    // return find_min_helper2(data, 0, 0, iterations);
    
    std::unordered_map<int, int> memo;
    return find_min_helper2_memo(data, 0, 0, memo, iterations);
}

// Unit tests for alg.
void test_alg(const Array2D& data, int expected) {
    int it{0};
    std::cout << "Alg test: " << (find_min(data, it) == expected ? "PASSED" : "FAILED") << " (iterations: " << it << ")" << std::endl;
}

void run_alg_tests() {
    
    {
        SourceData s = {{3, 1, 1}, {1, 1, 1}, {1, 1, 2}};
        Array2D data(s, 3, 3);
        test_alg(data, 8);
    }
    
    // 11
    {
        SourceData s = {{1, 2, 3}, {5, 0, 1}, {1, 1, 1}};
        Array2D data({{1, 2, 3}, {5, 0, 1}, {1, 1, 1}}, 3, 3);
        test_alg(data, 5);
    }
    
    {
        SourceData s = {{1, 2, 3}, {5, 7, 3}, {1, 2, 2}};
        Array2D data(s, 3, 3);
        test_alg(data, 11);
    }
}


int main()
{
    // Testing helper functions.
    test_2ddata();
    
    // Testing algorithm itself.
    run_alg_tests();

    return 0;
}