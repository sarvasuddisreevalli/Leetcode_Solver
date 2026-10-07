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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newhead=nullptr,*prev=nullptr;
        while(head && head->next){
            ListNode* temp=head->next->next;
            if(!prev) {
                newhead=head->next;
                prev=head;
                head->next->next=head;
                head->next=temp;
            }
            else {
                prev->next=head->next;
                head->next->next=head;
                head->next=temp;
                prev=head;
            }
            head=head->next;
        }
        return newhead;
    }
};