
// Given 3 not non-decreasing arrays. Find common value.
// Input: [1,2,4,5], [3,3,4], [2,3,4,5,6]
// Output: 4

#include <iostream>
#include <vector>
#include <optional>

using InputData = std::vector<int>;

// ALG SECTION

// Use 3 iterators for each array.
// Time-complexity: O(m + n + k)
// Mem complexity: O(1)
std::optional<int> solve(const InputData& v1, const InputData& v2, const InputData& v3) {

    if (v1.empty() || v2.empty() || v3.empty()) return std::nullopt;

    auto it1 = v1.begin();
    auto it2 = v2.begin();
    auto it3 = v3.begin();

    bool changed = false;

    while (it1 != v1.end() && it2 != v2.end() && it3 != v3.end()) {

        if (*it1 == *it2 && *it1 == *it3) return *it1;

        if (*it1 < *it2 || *it1 < *it3) {
            ++it1;
            changed = true;
        }

        if (it1 == v1.end()) break;

        if (*it2 < *it1 || *it2 < * it3) {
            ++it2;
            changed = true;
        }

        if (it2 == v2.end()) break;

        if (*it3 < *it1 || *it3 < * it2) {
            ++it3;
            changed = true;
        }

        if (it3 == v3.end()) break;
    }

    return std::nullopt;
}

// TESTING SECION
void test(const InputData& v1, const InputData& v2, const InputData& v3, const std::optional<int>& expected) {

    auto solution = solve(v1, v2, v3);
    std::cout << (solution == expected ? "PASSED" : "FAILED") << std::endl;
}

void run_all_tests() {

    {
        const InputData v1 = {1, 2, 4, 5};
        const InputData v2 = {3, 3, 4};
        const InputData v3 = {2, 3, 4, 5, 6};
        test(v1, v2, v3, 4);
    }

    {
        const InputData v1 = {1};
        const InputData v2 = {1};
        const InputData v3 = {1};
        test(v1, v2, v3, 1);
    }

    {
        const InputData v1 = {-2, 3, 5};
        const InputData v2 = {3};
        const InputData v3 = {2, 3};
        test(v1, v2, v3, 3);
    }

    {
        const InputData v1 = {-1};
        const InputData v2 = {1};
        const InputData v3 = {2};
        test(v1, v2, v3, std::nullopt);
    }

    {
        const InputData v1 = {};
        const InputData v2 = {};
        const InputData v3 = {};
        test(v1, v2, v3, std::nullopt);
    }

    {
        const InputData v1 = {1};
        const InputData v2 = {1};
        const InputData v3 = {1};
        test(v1, v2, v3, 1);
    }
}

int main() {

    run_all_tests();

    return 0;
}
