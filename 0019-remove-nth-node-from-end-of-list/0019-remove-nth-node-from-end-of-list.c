/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp=head;
    int cnt=1;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    temp=head;
    if(cnt-1==n){
        struct ListNode* p1=head->next;
        head=p1;
        return head;
    }
    int c=1;
    if(cnt-n<0)return head;
    while(c<cnt-n-1){
        temp=temp->next;
        c++;
    }
    struct ListNode* p1=temp->next;
    if(p1!=NULL) {
        struct ListNode* p2=p1->next;
        temp->next=p2;
    }
    else temp->next=p1;
    return head;
}