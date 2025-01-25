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
    ListNode* insertAtTail(int value,ListNode *&head , ListNode* &tail){
        ListNode* newNode = new ListNode(value);
        if(head == nullptr && tail == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        return tail;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1,* curr2 = l2;
        int carry = 0;
        ListNode* ansHead = nullptr, *ansTail = nullptr;
        while(curr1 != nullptr && curr2 !=nullptr){
            int sum =    curr1->val + curr2->val + carry;
            int digit = sum%10;
            carry = sum/10;
            insertAtTail(digit,ansHead,ansTail);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while(curr1 != nullptr){
            int sum =    curr1->val  + carry;
            int digit = sum%10;
            carry = sum/10;
            insertAtTail(digit,ansHead,ansTail);
            curr1 = curr1->next;
            
        }

        while(curr2 != nullptr){
            int sum =   curr2->val + carry;
            int digit = sum%10;
            carry = sum/10;
            insertAtTail(digit,ansHead,ansTail);
            curr2 = curr2->next;
        }

        if(carry != 0){
            insertAtTail(carry,ansHead,ansTail);
            carry /=10;
        }

        return ansHead;
    }
};