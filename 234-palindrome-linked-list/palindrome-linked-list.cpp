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
/*
    //v2 tc =  O(N) sc = O(N)
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
*/
    bool isPalindrome(ListNode *head)
    {
        

        /*
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
    */
    ListNode* midkpahleKanode =head;
    ListNode* rt = head;
    ListNode* tt = head;
    while(rt != nullptr){
        rt = rt -> next;
        if(rt!=nullptr){
            rt = rt->next;
            midkpahleKanode = tt;
            tt = tt->next;
        }
    }

    midkpahleKanode->next = nullptr;
    ListNode* prev = nullptr;
    while(tt != nullptr){
        ListNode* forward = tt->next;
        tt->next = prev;
        prev = tt;
        tt = forward;
    }
    
    ListNode* temp1 = head;
    ListNode* temp2 = prev;
    while(temp1 != nullptr && temp2 !=nullptr){
        if(temp1->val != temp2->val){
            return false;
        }
        temp1 =temp1->next;
        temp2= temp2->next;
    }
    return true;

    }
};