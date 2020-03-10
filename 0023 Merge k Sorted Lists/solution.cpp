/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // 我不确定这么写算不算作弊，，，反正能过
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* preHead = new ListNode(-1);
        ListNode* p = preHead;
        vector<int> rec;
        for (ListNode* temp: lists) {
            while (temp != NULL) {
                rec.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(rec.begin(), rec.end());
        for (int temp: rec) {
            p->next = new ListNode(temp);
            p = p->next;
        }
        return preHead->next;
    }
};


// 摆一个正常的方法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0)
            return NULL;

        while(lists.size() > 1){
            int index = 0;
            for(int i = 0; i < lists.size() ; i += 2){
                if(i + 1 == lists.size())
                    lists[index] = lists[i];
                else
                    lists[index] = merge(lists[i], lists[i + 1]);
                index ++;
            }

            while(lists.size() > index)
                lists.pop_back();
        }
        return lists[0];
    }

private:
    ListNode* merge(ListNode* list1, ListNode* list2){

        ListNode* dummyHead = new ListNode(-1);
        ListNode* curNode = dummyHead;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                curNode->next = list1;
                list1 = list1->next;
            }
            else{
                curNode->next = list2;
                list2 = list2->next;
            }

            curNode = curNode->next;
            curNode->next = NULL;
        }

        if(list1)
            curNode->next = list1;
        if(list2)
            curNode->next = list2;

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};