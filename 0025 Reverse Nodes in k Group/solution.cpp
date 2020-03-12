/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (k == 1) return head;

        ListNode* p1 = head;
        for (int i = 1; i < k; i++)
            p1 = p1 ? p1->next : NULL;
        if (p1 == NULL) return head;

        ListNode* then = p1->next;
        ListNode* p2 = head->next->next;
        ListNode* temp = head->next;
        head->next->next = head;
        while (p2 != then) {
            ListNode* t = p2;
            p2 = p2->next;
            t->next = temp;
            temp = t;
        }
        head->next = reverseKGroup(then, k);
        return p1;
    }
};