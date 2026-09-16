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
    ListNode* Create(int val){
        struct ListNode* nn=new ListNode(val);
        nn->next=nullptr;
        return nn;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct ListNode* h=nullptr;
        struct ListNode* tail=nullptr;
        vector<int>m;
        for(auto i : lists){
            while(i){
                m.push_back(i->val);
                i=i->next;
            }
        }
        sort(m.begin(),m.end());
        for(auto i : m){
            ListNode* nn=Create(i);
            if(h==NULL){
                h=nn;
                tail=nn;
            }
            else {
                tail->next=nn;
                tail=nn;
            }
        }
        return h;
    }
};