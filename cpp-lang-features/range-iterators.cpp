
#include <iterator>
#include <vector>

// we need to have begin/end implemented.
class TestContainer {

    std::vector<int> data;

    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using value_type = int;
        using pointer = int*;
    };

    Iterator begin() {
        return Iterator(data[0]);
    }

    Iterator end() {

    }

};

int main() {

    Test test;

    for (auto elem : test) {

    }

    return 0;
}