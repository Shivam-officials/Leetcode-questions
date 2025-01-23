/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool> map;
        ListNode* cur = head;
        while(cur != nullptr){
            if(map[cur] == true ){
                return true;
            }

            map[cur] = true;
            cur = cur->next;

        }
        return false;
    }
};