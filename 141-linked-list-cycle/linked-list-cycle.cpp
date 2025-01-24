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
        // unordered_map<ListNode*,bool> map;
        // ListNode* cur = head;
        // while(cur != nullptr){
        //     if(map.find(cur) != map.end() ){
        //         return true;
        //     }

        //     map[cur] = true;
        //     cur = cur->next;

        // }
        // return false;

        //edge cases
        if(head == nullptr)return false;
        if(head->next==nullptr)return false;
        ListNode* rabbit = head;
        ListNode* tort = head;
        while(rabbit != nullptr  ){
            rabbit = rabbit->next;

            if(rabbit != nullptr){
                
                rabbit = rabbit->next;
                tort = tort->next;

                if(rabbit != nullptr && rabbit == tort){
                    return true;
                }
            
            }
        }
        return false;
    }
};