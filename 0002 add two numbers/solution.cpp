/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ��һ˵һ�������������˱�׼��Ĭд��һ�顣�������ҵ�һ�����Ĵ���𰸣�1663��ͨ����1653��������Ҳ�鲻������������׼��������ȫ��Ⲣ�����ˡ�

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int len1 = getLen(l1), len2 = getLen(l2);
        ListNode *p1 = len1 > len2 ? l1 : l2;
        ListNode *p2 = len1 > len2 ? l2 : l1;

        ListNode *pre = NULL;
        int carried = 0;
        while(p1){

            int a = p1->val;
            int b = p2 ? p2->val : 0;
            p1->val = (a + b + carried) % 10;
            carried = (a + b + carried) / 10;

            pre = p1;
            p1 = p1->next;
            p2 = p2 ? p2->next : NULL;
        }
        pre->next = carried ? new ListNode(1) : NULL;
        return len1 > len2 ? l1 : l2;
    }

private:
    int getLen(ListNode *l) {
        int res = 0;
        while(l) {
            res++, l = l->next;
        }
        return res;
    }
};

// ��һ�����Ĵ���𰸣��Լ������²��Լ�ˮƽʮ����⡣ֻ���������ˡ�

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l = new ListNode(-1);
        ListNode* l1cur = l;
        ListNode* l2cur = l;

        while(NULL != l1){
            l1cur->next = new ListNode(l1->val);
            l1 = l1->next;
            l1cur = l1cur->next;
        }

        while(NULL != l2){
            if(NULL == l2cur->next){
                carry += l2->val;
                if(carry >= 10){
                    l2cur->next = new ListNode(carry - 10);
                    carry = 1;
                }else{
                    l2cur->next = new ListNode(carry);
                    carry = 0;
                }
            }else{
                carry = l2cur->next->val + carry;
                carry += l2->val;
                if(carry >= 10){
                    l2cur->next->val = carry - 10;
                    carry = 1;
                }else{
                    l2cur->next->val = carry;
                    carry = 0;
                }
            }
            l2 = l2->next;
            l2cur = l2cur->next;
        }
        while(carry == 1){
            if(NULL == l2cur->next){
                l2cur->next = new ListNode(1);
                carry = 0;
            }else{
                carry = l2cur->next->val + 1;
                if(carry >= 10){
                    l2cur->next->val = carry - 10;
                    carry = 1;
                }else{
                    l2cur->next->val = carry;
                    carry = 0;
                }
            }
        }
        return l->next;
    }
};