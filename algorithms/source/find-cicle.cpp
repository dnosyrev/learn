
// Given linked list. Find a cicle.
// Floyd-algorithm. Алгоритм Черепаха и Заяц.

#include <iostream>
#include <optional>

struct Node {
    int val;
    Node* next;
};

// ALG SECTION

// Floyd-algorithm. Алгоритм Черепаха и Заяц.
// Use two pointers: fast and slow. Fast = 2*slow speed.
// Return true if a cicle exists.
// Complexity?
bool solve(Node* node) {

    if (node == nullptr) return false;
    // if (node->next == nullptr) return false;

    Node* ptrFast = node;
    Node* ptrSlow = node;

    while (ptrFast && ptrSlow) {

        if (ptrFast->next == nullptr || ptrSlow->next == nullptr) return false;

        ptrSlow = ptrSlow->next;
        ptrFast = ptrFast->next;
        if (ptrFast == nullptr) return false;
        ptrFast = ptrFast->next;

        if (ptrFast == ptrSlow) return true;
    }

    // If a cicle exists, both should point to the same value.
    return false;
}

std::optional<Node*> solve2(Node* node) {

    if (node == nullptr) return std::nullopt;
    // if (node->next == nullptr) return false;

    Node* ptrFast = node;
    Node* ptrSlow = node;

    bool found = false;

    while (ptrFast && ptrSlow) {

        if (ptrFast->next == nullptr || ptrSlow->next == nullptr) return std::nullopt;

        ptrSlow = ptrSlow->next;
        ptrFast = ptrFast->next;
        if (ptrFast == nullptr) return std::nullopt;
        ptrFast = ptrFast->next;

        if (ptrFast == ptrSlow) {
            found = true;
            break;
        }
    }

    if (!found) return std::nullopt;

    ptrSlow = node;
    while (ptrSlow != ptrFast) {
        ptrFast = ptrFast->next;
        ptrSlow = ptrSlow->next;
    }

    // Both pointers points to cicle start.
    return ptrFast;
}

// TESTING SECTION
void test(Node* node, bool expected) {
    auto solution = solve(node);
    std::cout << "ALG1: " << (solution == expected ? "PASSED" : "FAILED") << std::endl;
}

void test2(Node* node, std::optional<Node*> expected) {
    auto solution = solve2(node);
    std::cout << "ALG2: " << (solution == expected ? "PASSED" : "FAILED") << std::endl;
}

void test_all() {
    {
        Node* n3 = new Node{.next = nullptr, .val = 3};
        Node* n2 = new Node{.next = n3, .val = 2};
        Node* n1 = new Node{.next = n2, .val = 1};
        n3->next = n2;
        test(n1, true);
        test(n1, n2);
    }

    {
        Node* n3 = new Node{.next = nullptr, .val = 3};
        Node* n2 = new Node{.next = n3, .val = 2};
        Node* n1 = new Node{.next = n2, .val = 1};
        n3->next = n1;
        test(n1, true);
        test2(n1, n1);
    }

    {
        Node* n3 = new Node{.next = nullptr, .val = 3};
        Node* n2 = new Node{.next = n3, .val = 2};
        Node* n1 = new Node{.next = n2, .val = 1};
        n3->next = n3;
        test(n1, true);
        test2(n1, n3);
    }

    {
        Node* n3 = new Node{.next = nullptr, .val = 3};
        Node* n2 = new Node{.next = n3, .val = 2};
        Node* n1 = new Node{.next = n2, .val = 1};
        test(n1, false);
        test2(n1, std::nullopt);
    }

    {
        Node* n1 = new Node{.next = nullptr, .val = 1};
        test(n1, false);
        test2(n1, std::nullopt);
    }

    {
        Node* n1 = new Node{.val = 1};
        n1->next = n1;
        test(n1, true);
        test2(n1, n1);
    }
}

int main() {

    test_all();

    return 0;
}