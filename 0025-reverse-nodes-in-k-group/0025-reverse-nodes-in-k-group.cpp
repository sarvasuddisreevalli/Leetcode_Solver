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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* temp=head;
        while(temp){
            int c=0;
            ListNode* t=temp;
            vector<int>v;
            while(c<k && t){
                v.push_back(t->val);
                t=t->next;
                c++;
            }
            if(c==k){
                while(c>0){
                    temp->val=v[c-1];
                    temp=temp->next;
                    c--;
                }
            }
            else break;
        }
        return head;
    }
};