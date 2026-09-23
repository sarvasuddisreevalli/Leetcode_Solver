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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* temp=list1,*prev=temp;
        while(list1 && list2) {
            if(list2->val<list1->val) {
                ListNode* t=list2;
                list2=list2->next;
                t->next=list1->next;
                list1->next=t;
                swap(list1->val,list1->next->val);
            }
            prev=list1;
            list1=list1->next;
        }
        if(list2) {
            // list1->val=list2->val;
            prev->next=list2;
        }
        return temp;
    }
};