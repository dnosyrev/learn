
#include <iostream>

int main() {

    int a[] = {1, 2, 3, 4};

    // C++ 20 feature - range-based for with index.
    for (std::size_t i = 0; const auto& elem : a) {
        std::cout << i++ << ":" << elem << ", ";
    }

    std::cout << "\n----" << std::endl;

    // testing another for.
    int aa[2][2] = {{1, 2}, {2, 3}};

    for (std::size_t i = 0; auto& [first, second] : aa) {
        std::cout << i++ << ":" << first<< ":" << second << ", "; 
    }

    return 0;
}