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

    int cnt;
    void rec(ListNode* n,int i){
        if(n!=NULL){
            cnt++;
            rec(n->next,i+1);
        }
        if(i==(cnt/2-1) && n->next)
            n->next=n->next->next;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL){
            ListNode* n=NULL;
            return n;
        }
        cnt=0;
        rec(head,0);
        return head;
    }
};