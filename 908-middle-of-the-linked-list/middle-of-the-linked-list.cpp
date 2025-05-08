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
    ListNode* middleNode(ListNode* head) {
      ListNode* tt = head;
      ListNode* rt = head;
      while(rt != nullptr){
        rt = rt->next;
        if(rt!=nullptr){
            rt = rt->next;
            
                tt = tt->next;
            
        }
      }
      return tt;
    }
};