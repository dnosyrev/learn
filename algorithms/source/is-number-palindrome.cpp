
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// To check if an integer is a palindrome or not.

class Solution {
public:
    static bool isPalindrome1(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        // vector<int> digits;
        // bool found = false;
        int digits = std::log10(x) + 1;
        for (int i = 0; i < digits / 2; ++i) {
            int digit1 = (int)(x / pow(10, i)) % 10;
            // if (!found && digit == 0) {
            //     continue;
            // }
            // found = true;

            int digit2 = (int)(x / pow(10, (digits - i - 1))) % 10;

            if (digit1 != digit2) return false;
            // digits.push_back(digit);
        }

        // auto it_begin = digits.begin();
        // auto it_end = digits.end() - 1;
        // while (it_begin < it_end) {
        //     if (*it_begin != *it_end) {
        //         return false;
        //     }

        //     ++it_begin;
        //     --it_end;
        // }

        return true;
    }

    static bool isPalindrome(int x) {

        int reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }
    }
};

void print_test_result(int number, bool expected) {
    std::cout << "test alg: " << (Solution::isPalindrome(number) == expected ? "PASSED" : "FAILED") << std::endl;
}

void run_tests() {
    print_test_result(121, true);
    print_test_result(123321, true);
    print_test_result(1211, false);
}

int main()
{

    run_tests();

    return 0;
}