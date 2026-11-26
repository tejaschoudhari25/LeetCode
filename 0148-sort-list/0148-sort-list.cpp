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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* temp = new ListNode(0);
        ListNode* curr = temp;

        while(left != nullptr && right != nullptr) {
            if(left->val <= right->val) {
                curr->next = new ListNode(left->val);
                left = left->next;
            }
            else {
                curr->next = new ListNode(right->val);
                right = right->next;
            }

            curr = curr->next;
        }

        while(left != nullptr){
            curr -> next = new ListNode(left->val);
            curr = curr -> next;
            left = left -> next;
        }
        while(right != nullptr){
            curr -> next = new ListNode(right->val);
            curr = curr -> next;
            right = right -> next;
        }

        return temp -> next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
           return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast != nullptr && fast -> next != nullptr){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left, right);
    }
};