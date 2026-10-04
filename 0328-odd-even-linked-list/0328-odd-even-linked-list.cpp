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
    ListNode* oddEvenList(ListNode* head) {
        vector<int>odd;
        vector<int>even;
        struct ListNode* temp=head;
        int cnt=0;
        while(temp){
            if(cnt&1)odd.push_back(temp->val);
            else even.push_back(temp->val);
            temp=temp->next;
            cnt++;
        }
        temp=head;
        reverse(odd.begin(),odd.end());
        reverse(even.begin(),even.end());
        while(even.size()>0){
            temp->val=even[even.size()-1];
            temp=temp->next;
            even.pop_back();
        }
        while(odd.size()>0){
            temp->val=odd[odd.size()-1];
            temp=temp->next;
            odd.pop_back();
        }
        return head;
    }
};