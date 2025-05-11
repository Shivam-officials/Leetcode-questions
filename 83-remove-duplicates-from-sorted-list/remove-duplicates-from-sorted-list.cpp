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
        
        //edge cases 
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr != nullptr){
            if(curr->val == prev->val){
                ListNode* forward = curr->next;
                prev->next = forward;
                curr->next = nullptr;
                delete curr;
                curr = forward;
            }else{
                prev = prev->next;
                curr = curr->next;
            }
        }
       return head; 
    }
};