
// Given matrix RxC, try to find all possible paths from left bottom corner to the right upper corner.
// It's possible to move only to right or top.
// E.g.:
// Input: 2x2
// Output: 2

#include <iostream>
#include <unordered_map>

// ALGORITHM SECTION.
class Solution {

public:

    int solve(std::tuple<int, int> dimensions) {

        auto rows = std::get<0>(dimensions);
        auto cols = std::get<1>(dimensions);
        return solve_helper(rows, cols, rows - 1, 0);
    }

    int iterations = 0;

private:

    int solve_helper(int row, int col, int pos_row, int pos_col) {

        ++iterations;

        if (pos_row == 0 && pos_col == col - 1) return 1;

        int s1 = 0;
        int s2 = 0;
        if (pos_row > 0) s1 = solve_helper(row, col, pos_row - 1, pos_col);
        if (pos_col < col - 1) s2 = solve_helper(row, col, pos_row, pos_col + 1);

        return s1 + s2;
    }
};

// With memo.
class Solution2Memo {

public:

    int solve(std::tuple<int, int> dimensions) {

        auto rows = std::get<0>(dimensions);
        auto cols = std::get<1>(dimensions);
        return solve_helper(rows, cols, rows - 1, 0);
    }

    int iterations = 0;

private:

    using Memo = std::unordered_map<int, int>;
    Memo memo;

    int solve_helper(int row, int col, int pos_row, int pos_col, Memo& memo) {

        ++iterations;

        if (pos_row == 0 && pos_col == col - 1) return 1;

        if (auto it = memo.find(pos_row * col + pos_col); it != memo.end()) {
            return memo[pos_row * col + pos_col];
        }

        int s1 = 0;
        int s2 = 0;
        if (pos_row > 0) {
            s1 = solve_helper(row, col, pos_row - 1, pos_col, memo);
            memo[(pos_row - 1) * col + pos_col] = s1;
        }
        if (pos_col < col - 1) {
            s2 = solve_helper(row, col, pos_row, pos_col + 1, memo);
            memo[pos_row * col + pos_col + 1] = s2;
        }

        return s1 + s2;
    }

    int solve_helper(int row, int col, int pos_row, int pos_col) {
        Memo memo;
        return solve_helper(row, col, pos_row, pos_col, memo);
    }
};


// TESTING SECTION.

void test(std::tuple<int, int> dimensions, int expected) {
    Solution2Memo sol;
    auto out = sol.solve(dimensions);
    std::cout << "ALG: " << (out == expected ? "PASSED" : "FAILED ");
    if (out != expected) {
        std::cout << " (out is " << out << ")";
    } else {
        std::cout << " (iterations are " << sol.iterations << ")";
    }
    std::cout << std::endl;
}

void all_tests() {
    
    test({2, 2}, 2);
    test({2, 3}, 3);
    test({3, 3}, 6);
    test({10, 12}, 167960);
}

int main() {

    all_tests();

    return 0;
}