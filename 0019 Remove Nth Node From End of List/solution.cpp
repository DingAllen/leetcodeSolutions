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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* p = head;
        vector<ListNode*> rec;
        int nums = 0;
        while (p != NULL) {
            rec.push_back(p);
            nums++;
            p = p->next;
        }
        if (nums == n) return head->next;
        ListNode* o = rec[nums - n - 1];
        o->next = o->next->next;
        return head;
    }
};