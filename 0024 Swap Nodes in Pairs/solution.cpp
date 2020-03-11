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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* p = dummyHead;
        while (p->next != NULL) {
            if (p->next->next != NULL) {
                ListNode* temp1 = p->next;
                ListNode* temp2 = p->next->next->next;
                p->next = p->next->next;
                p->next->next = temp1;
                p->next->next->next = temp2;
                p = p->next->next;
            } else break;
        }
        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};


// 很强的递归手法，不是我写的，但学到了
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* tmp = head;
        head = head->next;
        tmp->next=head->next;
        head->next=tmp;
        head->next->next=swapPairs(head->next->next);
        return head;
    }
};