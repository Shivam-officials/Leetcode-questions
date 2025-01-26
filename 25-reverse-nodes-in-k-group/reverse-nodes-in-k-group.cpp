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
      void reverese(ListNode* &groupStart, ListNode* &groupEnd) {
    // Reverse the sublist between groupStart and groupEnd
    ListNode* prev = nullptr;
    ListNode* forEnd = groupStart; // Store the original start of the group
    ListNode* curr = groupStart;

    while (curr != nullptr) {
        ListNode* forward = curr->next; // Store the next ListNode
        curr->next = prev;          // Reverse the current ListNode
        prev = curr;                // Move prev and curr one step forward
        curr = forward;
    }

    // Update groupStart to the new head of the reversed group
    groupStart = prev; 
    groupEnd = forEnd; // Update groupEnd to the original groupStart
}

ListNode* reverseKGroup(ListNode* head, int k) {
    int count = 0; 
    ListNode* prev = nullptr; // End of the previous processed group
    ListNode* groupStart = head; // Start of the current group
    ListNode* curr = head;       // Current ListNode in the list
    ListNode* groupEnd = nullptr; // End of the current group
    ListNode* forward = nullptr; // Next ListNode after the current group

    while (curr != nullptr) {
        count++;

        // When a group of size k is found or it's the end of the list
        if (count % k == 0 ) {
            groupEnd = curr;          // End of the current group
            forward = curr->next;     // Save the next ListNode after the group

            if (prev != nullptr) {
                prev->next = nullptr; // Disconnect the previous group from the current one
            }
            groupEnd->next = nullptr; // Disconnect the current group from the next

            // Reverse the current group
            reverese(groupStart, groupEnd);

            // Connect the reversed group back to the list
            if (prev != nullptr) {
                prev->next = groupStart;
            } else {
                head = groupStart;    // Update head for the first group
            }

            groupEnd->next = forward; // Connect the group end to the next part
            prev = groupEnd;          // Update prev to the end of the current group
            groupStart = forward;     // Move to the next group
            
            //note: This below step is essential to avoid re-processing the same ListNodes.
            // Move curr to the start of the next group
            curr = groupStart; 
        } else {
            curr = curr->next; // Move to the next ListNode
        }
    }

    return head;
}
};