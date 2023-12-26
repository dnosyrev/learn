
#include <iostream>

// Check std::is_same type traits and try own implementation.

// struct TrueType {
//     const static bool value = true;
// };

// struct FalseType {
//     const static bool value = false;
// };

namespace dim {

template <typename A, typename B>
struct is_same {
    const static bool value = false;
};

template <typename A>
struct is_same<A, A> {
    const static bool value = true;
};

}

int main() {

    std::cout << (std::is_same<int, int32_t>::value) << std::endl; // perhaps the same
    std::cout << (std::is_same<int, uint32_t>::value) << std::endl; 

    std::cout << (dim::is_same<int, int32_t>::value) << std::endl; // perhaps the same

    std::cout << ((std::is_same<int, int>::value == dim::is_same<int, int>::value) ? "PASSED" : "FAILED") << std::endl;
    std::cout << ((std::is_same<int, uint32_t>::value == dim::is_same<int, uint32_t>::value) ? "PASSED" : "FAILED") << std::endl;

    return 0;
}