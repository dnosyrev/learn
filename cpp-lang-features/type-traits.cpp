
#include <iostream>
#include <type_traits>


int main() {

    // Resolved at compile time.
    if constexpr (std::is_floating_point<float>::value) {
        std::cout << "trace 1" << std::endl;
    } else {
        std::cout << "trace 2" << std::endl;
    }

    std::cout << std::is_signed<int>::value << std::endl;

    return 0;
}