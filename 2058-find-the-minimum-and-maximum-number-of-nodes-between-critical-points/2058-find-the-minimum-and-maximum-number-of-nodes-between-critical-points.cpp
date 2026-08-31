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

    int s=-1,mid=1e9,p=-1,mxd=-1;
    void fun(int prv,ListNode* head,int cur) {
        if(head->next!=nullptr) {
            if(prv != -1) {
                if((prv>head->val && head->next->val>head->val) || (prv<head->val && head->next->val<head->val)) {
                    if(p==-1) {
                        p = cur;
                        s = cur;
                    }else{ 
                        mid = min(mid,cur-p);
                        mxd = cur-s;
                        p = cur;
                    }
                }
            }
            fun(head->val,head->next,cur+1);
        }
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==nullptr || head->next->next==nullptr)
            return {-1,-1};
        fun(-1,head,1);
        if(mxd==-1)
            return {-1,-1};
        return {mid,mxd};
    }
};