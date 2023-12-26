
#include <iostream>

// Check template specialization. Partial and full.

template <typename A, typename B>
class Test {
public:
    
    void calc(A a, B b) {
        std::cout << a << ", " << b << std::endl;
    }
};

template <typename A>
class Test<A, float> {
public:
    
    void calc(A a, float b) {
        std::cout << "partial specialized with second float: " << a << ", " << b << std::endl;
    }
};

template <>
class Test<float, float> {
public:
    
    void calc(int a, float b) {
        std::cout << "partial specialized with first float and second float: " << a << ", " << b << std::endl;
    }
};


int main() {
    
    {
        Test<int, int> t;
        t.calc(1, 2);
    }

    {
        Test<int, float> t;
        t.calc(1, 2);
    }

    {
        Test<float, float> t;
        t.calc(1, 2);
    }

    return 0;
}