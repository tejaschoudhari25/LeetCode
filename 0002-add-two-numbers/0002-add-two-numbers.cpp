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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;

        ListNode *newHead = new ListNode(0);
        ListNode *temp3 = newHead;

        int carry = 0;
        while(temp1 != NULL || temp2 != NULL)
        {
            int x = (temp1? temp1 -> val : 0);
            int y = (temp2 ? temp2 -> val : 0);
            int sum = x + y + carry;

            carry = sum / 10;
            temp3->val = sum % 10;

            if ((temp1 && temp1->next) || (temp2 && temp2->next)) 
            {
                temp3->next = new ListNode(0); 
                temp3 = temp3->next;
            } 
            else if (carry) 
            {
                temp3->next = new ListNode(carry);
                temp3 = temp3->next;
                carry = 0;
            }
            if(temp1) temp1 = temp1 -> next;
            if(temp2) temp2 = temp2 -> next; 
        }
        return newHead;
    }
};