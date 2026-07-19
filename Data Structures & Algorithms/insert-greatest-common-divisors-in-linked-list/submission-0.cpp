#include <numeric>

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            ListNode* node = new ListNode(std::gcd(curr->val, curr->next->val));

            node->next = curr->next;
            curr->next = node;

            curr = node->next;
        }

        return head;
    }
};