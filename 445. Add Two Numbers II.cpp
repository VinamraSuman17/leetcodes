/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* l) {
        if (l == NULL || l->next == NULL)
            return l;

        ListNode* temp = reverseLL(l->next);

        l->next->next = l;
        l->next = NULL;

        return temp;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverseLL(l1);
        ListNode* r2 = reverseLL(l2);
        ListNode* result = NULL;
        int carry = 0;

        while (r1 != NULL || r2 != NULL) {
            int addition = carry;

            if (r1 != NULL) {
                addition += r1->val;
                r1 = r1->next;
            }

            if (r2 != NULL) {
                addition += r2->val;
                r2 = r2->next;
            }

            int val = addition % 10;
            carry = addition / 10;

            result = result ? new ListNode(val, result) : new ListNode(val);
        }

        if (carry) {
            result = new ListNode(carry, result);
        }

        return result;
    }
};