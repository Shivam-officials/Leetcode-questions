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
    ListNode* deleteDuplicates(ListNode* head) {
      if(head == nullptr || head->next == nullptr)return head;  
      ListNode* curr = head->next;
      ListNode* prev = head;

      while(curr!=nullptr){
        if(prev->val == curr->val){
            ListNode* forward = curr->next;

            if( forward != nullptr){
               prev->next = forward;
               curr->next = nullptr;
               delete curr;
               curr = forward;
            }else{
                prev->next = nullptr;
                delete curr;
                curr = nullptr;
            }
        }else{
            prev = curr;
            curr = curr->next;
        }
      }
      return head;
    }
};