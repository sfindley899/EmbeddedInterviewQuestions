#include <vector>
#include <iostream>
#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int count_list_len(ListNode* head)
    {
        int count = 0;
        while (head != nullptr)
        {
            head = head->next;
            count++;
        }
        return count;
    }

    ListNode* middleNode2(ListNode* head) {
        
        int length = count_list_len(head);
        int target = length / 2;
        
        ListNode * curr = head;
        for (int i = 0; i < target; i++)
        {
            curr = curr->next;
        }

        return curr;
    }

    ListNode* middleNode(ListNode* head) {
        
        ListNode * fast = head, *slow = head;

        while((fast != nullptr) && (fast->next != nullptr))
        {
            fast = fast->next->next;
            slow = slow->next;
        }
 
        return slow;
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

int linked_list_to_value(ListNode* head) {
    if (head == nullptr) {
        return -1; // Return -1 to indicate that the list is empty
    }
    return head->val;
}

void test_middle_node() {
    Solution solution;

    // Test case 1
    ListNode* list1 = create_linked_list({1, 2, 3, 4, 5});
    ListNode* result1 = solution.middleNode(list1);
    assert(linked_list_to_value(result1) == 3);

    ListNode* result1_2 = solution.middleNode2(list1);
    assert(linked_list_to_value(result1_2) == 3);

    // Test case 2
    ListNode* list2 = create_linked_list({1, 2, 3, 4, 5, 6});
    ListNode* result2 = solution.middleNode(list2);
    assert(linked_list_to_value(result2) == 4);

    ListNode* result2_2 = solution.middleNode2(list2);
    assert(linked_list_to_value(result2_2) == 4);

    // Test case 3
    ListNode* list3 = create_linked_list({});
    ListNode* result3 = solution.middleNode(list3);
    assert(linked_list_to_value(result3) == -1);

    ListNode* result3_2 = solution.middleNode2(list3);
    assert(linked_list_to_value(result3_2) == -1);

    // Test case 4
    ListNode* list4 = create_linked_list({1});
    ListNode* result4 = solution.middleNode(list4);
    assert(linked_list_to_value(result4) == 1);

    ListNode* result4_2 = solution.middleNode2(list4);
    assert(linked_list_to_value(result4_2) == 1);

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    test_middle_node();
    return 0;
}
