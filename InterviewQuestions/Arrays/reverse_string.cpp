
#include <vector>
#include <iostream>
#include <cassert>

class Solution {
public:
    void reverseString(std::vector<char>& s) {

        if (s.empty())
        {
            return;
        }

        int start = 0;
        int end = s.size() - 1;

        while(start < end)
        {
            char c = s[start];
            s[start] = s[end];
            s[end] = c;

            start++;
            end--;
        }
    }
};

void test_reverse_string() {
    Solution solution;

    // Test case 1
    std::vector<char> input1 = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(input1);
    std::vector<char> expected1 = {'o', 'l', 'l', 'e', 'h'};
    assert(input1 == expected1);

    // Test case 2
    std::vector<char> input2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    solution.reverseString(input2);
    std::vector<char> expected2 = {'h', 'a', 'n', 'n', 'a', 'H'};
    assert(input2 == expected2);

    // Test case 3
    std::vector<char> input3 = {};
    solution.reverseString(input3);
    std::vector<char> expected3 = {};
    assert(input3 == expected3);

    // Test case 4
    std::vector<char> input4 = {'A'};
    solution.reverseString(input4);
    std::vector<char> expected4 = {'A'};
    assert(input4 == expected4);

    // Test case 5
    std::vector<char> input5 = {'1', '2', '3', '4', '5'};
    solution.reverseString(input5);
    std::vector<char> expected5 = {'5', '4', '3', '2', '1'};
    assert(input5 == expected5);

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    test_reverse_string();
    return 0;
}
