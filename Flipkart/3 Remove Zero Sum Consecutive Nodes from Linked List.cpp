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
 
  ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        map<int,ListNode*> mp;
        ListNode* cur = dummy;
        cur->next = head;
        cur = cur->next;
        int pref = 0;
        mp[pref] = dummy;
        while(cur) {
            pref += cur->val;
            if(mp.count(pref))  {
                cur = mp[pref]->next;
                int p = pref + cur->val;
                while(p != pref) {
                    mp.erase(p);
                    cur = cur->next;
                    p += cur->val;
                }
                mp[pref]->next = cur->next;
            }
            else {
                mp[pref] = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }

};
