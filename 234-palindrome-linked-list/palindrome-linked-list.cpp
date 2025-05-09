/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
/*
    ListNode* reverseListIteratively(ListNode* &head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* middleNode(ListNode* &head, ListNode* &midkPahleWalaNode)
    {
       	// Initialize two pointers: rabbit (fast pointer) and tortoise (slow pointer),
       	// both starting at the head of the linked list.
        ListNode *rabbit = head;
        ListNode *tortoise = head;

       	// Traverse the linked list.
       	// The rabbit pointer can moves two steps at a time, the tortoise can move one step at that time.
        while (rabbit != nullptr)
        {
           	// Move the rabbit pointer one step forward.
            rabbit = rabbit->next;

           	// Check if rabbit can take another step forward.
            if (rabbit != nullptr)
            {
               	// Move the rabbit pointer a second step forward.
                rabbit = rabbit->next;

               	// Move the tortoise pointer one step forward.
                midkPahleWalaNode = tortoise;
                tortoise = tortoise->next;
            }
        }

       	// When the rabbit pointer reaches the end of the list (or becomes nullptr),
       	// the tortoise pointer will be at the middle of the list.
        return tortoise;
    }
*/

    //v2 
    ListNode* insertAtHead(ListNode* &head,int &value){
        ListNode* newNode = new ListNode(value);
        if(head == nullptr){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
    bool isPalindrome(ListNode *head)
    {
        /*
            //edge cases 
            if(head->next == nullptr){
                return true;
            }

            if(head->next->next == nullptr){
                if(head->val == head->next->val){
                    return true;
                }else{
                    return false;
                }
            }

            ListNode *midKPhleWalaNode = nullptr;
            ListNode *newHead = middleNode(head, midKPhleWalaNode);

            //breaking the Linked List
            midKPhleWalaNode->next = nullptr;

            newHead = reverseListIteratively(newHead);
            ListNode *firsthead = head;
            ListNode *reversedHead = newHead;

            while (firsthead != nullptr)
            {
                if (firsthead->val != reversedHead->val)
                {
                    return false;
                }
                firsthead = firsthead->next;
                reversedHead = reversedHead->next;
            }
            return true;
        */
        ListNode* temp = head;
        ListNode*  newLLHead = nullptr;
        while(temp != nullptr){
            insertAtHead(newLLHead,temp->val);
            temp = temp->next;
        }
        ListNode* tempNew = newLLHead;
         temp = head;

        while(tempNew != nullptr){
            cout<<tempNew->val << "=="<<temp->val<<endl;
            if(tempNew-> val != temp->val) return false;
            tempNew = tempNew->next;
            temp = temp->next;
        }
    return true;

    }
};