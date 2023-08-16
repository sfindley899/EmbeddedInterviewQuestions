#include <vector>
#include <iostream>
#include <assert.h>

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

    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode dummy_head = ListNode();       
        dummy_head.next = head;
        ListNode * dummy = &dummy_head;

        int len = count_list_len(head);
        int k = len - n;

        for (int i = 0; i < k; i++)
        {
            dummy = dummy->next;
        }

        dummy->next = dummy->next->next;
        
        return dummy_head.next;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode dummy_head = ListNode();       
        dummy_head.next = head;
        ListNode * fast = &dummy_head,* slow = &dummy_head;

        for(int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }

        while((fast != nullptr) and (fast->next != nullptr))
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

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

void test_remove_nth_from_end() {
    Solution solution;

    // Test case 1
    ListNode* head1 = create_linked_list({1, 2, 3, 4, 5});
    ListNode* result1 = solution.removeNthFromEnd(head1, 2);
    std::vector<int> expected1 = {1, 2, 3, 5};
    assert(linked_list_to_list(result1) == expected1);

    // Test case 2
    ListNode* head2 = create_linked_list({1, 2, 3, 4, 5});
    ListNode* result2 = solution.removeNthFromEnd(head2, 1);
    std::vector<int> expected2 = {1, 2, 3, 4};
    assert(linked_list_to_list(result2) == expected2);

    // Test case 3
    ListNode* head3 = create_linked_list({1, 2, 3, 4, 5});
    ListNode* result3 = solution.removeNthFromEnd(head3, 5);
    std::vector<int> expected3 = {2, 3, 4, 5};
    assert(linked_list_to_list(result3) == expected3);

    // Test case 4
    ListNode* head4 = create_linked_list({1});
    ListNode* result4 = solution.removeNthFromEnd(head4, 1);
    std::vector<int> expected4 = {};
    assert(linked_list_to_list(result4) == expected4);

    // Test case 5
    ListNode* head5 = create_linked_list({});
    ListNode* result5 = solution.removeNthFromEnd(head5, 1);
    std::vector<int> expected5 = {};
    assert(linked_list_to_list(result5) == expected5);

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    test_remove_nth_from_end();
    return 0;
}
