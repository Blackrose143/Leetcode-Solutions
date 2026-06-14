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

    ListNode* l;
    int rec(ListNode* r){
        int ans=0;
        if(r->next!=NULL)
            ans=max(ans,rec(r->next));
        if(l!=r){
            ans=max(ans,l->val+r->val);
            l=l->next;
        }
        return ans;
    }
    int pairSum(ListNode* head) {
        ListNode* r=head;
        l=head;
        return rec(r);
    }
};