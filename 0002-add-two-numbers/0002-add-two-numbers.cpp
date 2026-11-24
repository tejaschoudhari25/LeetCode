class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* newHead = new ListNode(0);
        ListNode* curr = newHead;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;
            curr->val = sum % 10;

            if ((l1 != NULL && l1->next != NULL) ||
                (l2 != NULL && l2->next != NULL) ||
                carry != 0) {
                curr->next = new ListNode(0);
            }

            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;

            if (curr->next != NULL) {
                curr = curr->next;
            }
        }

        return newHead;
    }
};