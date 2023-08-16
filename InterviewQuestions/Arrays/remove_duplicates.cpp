#include <vector>
#include <iostream>
#include <cassert>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        
        if (nums.empty())
        {
            return 0;
        }
        
        int n = nums.size();
        int slow = 0;
        for(int fast = slow + 1; fast < n;)
        {
            if (nums[slow] == nums[fast])
            {
                fast++;
            }
            else
            {
                nums[slow + 1] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow + 1;
    }
};

void test_remove_duplicates() {
    Solution solution;

    // Test case 1
    std::vector<int> nums1 = {1, 1, 2};
    int result1 = solution.removeDuplicates(nums1);
    std::vector<int> expected1 = {1, 2};
    assert(result1 == expected1.size());
    assert(std::vector<int>(nums1.begin(), nums1.begin() + result1) == expected1);

    // Test case 2
    std::vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int result2 = solution.removeDuplicates(nums2);
    std::vector<int> expected2 = {0, 1, 2, 3, 4};
    assert(result2 == expected2.size());
    assert(std::vector<int>(nums2.begin(), nums2.begin() + result2) == expected2);

    // Test case 3
    std::vector<int> nums3 = {};
    int result3 = solution.removeDuplicates(nums3);
    std::vector<int> expected3 = {};
    assert(result3 == expected3.size());
    assert(std::vector<int>(nums3.begin(), nums3.begin() + result3) == expected3);

    // Test case 4
    std::vector<int> nums4 = {1};
    int result4 = solution.removeDuplicates(nums4);
    std::vector<int> expected4 = {1};
    assert(result4 == expected4.size());
    assert(std::vector<int>(nums4.begin(), nums4.begin() + result4) == expected4);

    // Test case 5
    std::vector<int> nums5 = {3, 3, 3, 3, 3};
    int result5 = solution.removeDuplicates(nums5);
    std::vector<int> expected5 = {3};
    assert(result5 == expected5.size());
    assert(std::vector<int>(nums5.begin(), nums5.begin() + result5) == expected5);

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    test_remove_duplicates();
    return 0;
}
