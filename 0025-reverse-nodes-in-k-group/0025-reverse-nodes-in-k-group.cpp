class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            // Find kth node
            ListNode* kth = groupPrev;

            for (int i = 1; i <= k && kth != NULL; i++) {
                kth = kth->next;
            }

            // Not enough nodes
            if (kth == NULL) {
                break;
            }

            // Save connections
            ListNode* groupNext = kth->next;
            ListNode* originalFirst = groupPrev->next;

            // Reverse the group
            ListNode* prev = groupNext;
            ListNode* curr = originalFirst;

            while (curr != groupNext) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect reversed group
            groupPrev->next = kth;

            // Move to next group
            groupPrev = originalFirst;
        }

        return dummy->next;
    }
};