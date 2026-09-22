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
        ListNode* temp=nullptr,*head=temp;
        while(list1 && list2) {
            ListNode* t=new ListNode();
            if(list1->val<list2->val) {
                t->val=list1->val;
                list1=list1->next;
            }
            else {
                t->val=list2->val;
                list2=list2->next;
            }
            if(!temp) {
                temp=t;
                head=temp;
            }
            else {
                temp->next=t;
                temp=temp->next;
            }
        }
        if(list1) {
            if(!temp) temp=list1;
            else temp->next=list1;
        }
        if(list2) {
            if(!temp) temp=list2;
            else temp->next=list2;
        }
        if(!head) head=temp;
        return head;
    }
};