
#include <iostream>

// Assume they are chars. Can be done via concepts.
template <typename First, typename ...Args>
void test(First first, Args...args) {
}

// Assume they are chars. Can be done via concepts.
template <typename First, typename ...Args>
std::string create_str(Args... args) {
    
    const char str[] = {args..., '\0'};
    return str;
}


int main() {

    std::cout << create_str<char>('s', 't', 'r') << std::endl;

    return 0;
}
