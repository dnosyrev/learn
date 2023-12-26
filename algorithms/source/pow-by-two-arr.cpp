
#include <iostream>
#include <vector>
#include <forward_list>

// Given sorted array of integer elements. Need to create an array of sorted powered by two elements (elem*elem).
// E.g:
// Input: [-5, -1, 0, 2, 7]
// Output: [0, 1, 4, 25, 49]

// Use two iterators: one from begin, one from the end.
// Time-complexity: O(n)
std::forward_list<int> solve(const std::vector<int>& input) {

    if (input.size() == 0) return {};

    std::forward_list<int> out;

    auto left = input.begin();
    auto right = input.end() - 1;
    
    while (left <= right) {

        if (std::abs(*left) > std::abs(*right)) {
            out.push_front((*left) * (*left));
            ++left;
        } else {
            out.push_front((*right) * (*right));
            --right;
        }
    }

    return out;
}


void test() {
    {
        std::vector<int> in = {1};
        std::forward_list<int> out = solve(in);

        for (auto elem : out) std::cout << elem << ", " << std::endl;

        std::cout << (out == std::forward_list<int>{1} ? "PASSED" : "FAILED") << std::endl;
    }

    {
        std::vector<int> in = {-1, 2};
        std::forward_list<int> out = solve(in);

        std::cout << (out == std::forward_list<int>{1, 4} ? "PASSED" : "FAILED") << std::endl;
    }

    {
        std::vector<int> in = {-5, -3, -1, 0, 2, 7};
        std::forward_list<int> out = solve(in);

        std::cout << (out == std::forward_list<int>{0, 1, 4, 9, 25, 49} ? "PASSED" : "FAILED") << std::endl;
    }
}

int main() {

    test();

    return 0;
}