
#include <iostream>
#include <string>

// Check the order which is used to initialize class members, call constructor body.

struct Node {
    std::string id;

    Node(std::string id) : id(id) {
        std::cout << "Node() - " << id << std::endl;
    }

    ~Node() {
        std::cout << "~Node() - " << id << std::endl;
    }
};

struct Base {
    Node n1;
    Node n2;

    Base() : n2("base-n2"), n1("base-n1") { // We init it in reverse order.
        std::cout << "Base()" << std::endl;
    }

    ~Base() {
        std::cout << "~Base()" << std::endl;
    }
};


int main() {

    Base b;

    return 0;
}