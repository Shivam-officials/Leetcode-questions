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

    ListNode* reverseListRe(ListNode* &prev, ListNode* &curr){
        if(curr == nullptr) return prev;

        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        return reverseListRe(prev,curr);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode*  prev = nullptr;
        return reverseListRe(prev,head);
    }
};