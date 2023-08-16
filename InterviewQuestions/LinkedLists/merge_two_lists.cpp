#include <vector>
#include <iostream>
#include <cassert>
#include <limits.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy_head = ListNode();
        ListNode * dummy = &dummy_head;

        while ((list1 != nullptr) or (list2 != nullptr))
        {
            int l1 = (list1 != nullptr) ? list1->val : INT_MAX; 
            int l2 = (list2 != nullptr) ? list2->val : INT_MAX; 
        
            if (l1 < l2)
            {
                dummy->next = list1;
                list1 = list1->next;
            }
            else
            {
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }

        return dummy_head.next;
    }
};

ListNode* create_linked_list(const std::vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }

    ListNode* dummy_head = new ListNode();
    ListNode* current = dummy_head;

    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }

    return dummy_head->next;
}

std::vector<int> linked_list_to_list(ListNode* head) {
    std::vector<int> result;
    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

void test_merge_two_lists() {
    Solution solution;

    // Test case 1
    ListNode* list1 = create_linked_list({1, 2, 4});
    ListNode* list2 = create_linked_list({1, 3, 4});
    ListNode* result1 = solution.mergeTwoLists(list1, list2);
    std::vector<int> expected1 = {1, 1, 2, 3, 4, 4};
    assert(linked_list_to_list(result1) == expected1);

    // Test case 2
    ListNode* list3 = create_linked_list({});
    ListNode* list4 = create_linked_list({});
    ListNode* result2 = solution.mergeTwoLists(list3, list4);
    std::vector<int> expected2 = {};
    assert(linked_list_to_list(result2) == expected2);

    // Test case 3
    ListNode* list5 = create_linked_list({});
    ListNode* list6 = create_linked_list({0});
    ListNode* result3 = solution.mergeTwoLists(list5, list6);
    std::vector<int> expected3 = {0};
    assert(linked_list_to_list(result3) == expected3);

    // Test case 4
    ListNode* list7 = create_linked_list({1, 5, 9});
    ListNode* list8 = create_linked_list({2, 3, 4});
    ListNode* result4 = solution.mergeTwoLists(list7, list8);
    std::vector<int> expected4 = {1, 2, 3, 4, 5, 9};
    assert(linked_list_to_list(result4) == expected4);

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    test_merge_two_lists();
    return 0;
}
