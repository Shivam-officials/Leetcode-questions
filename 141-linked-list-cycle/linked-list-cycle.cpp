/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        bool hasCycle(ListNode *head)
        {
         ListNode* rt = head;
         ListNode* tt = head;

        if(head == nullptr || head->next == nullptr)return false;

        while(rt != nullptr){
            rt= rt->next;
            if(rt!=nullptr){
                rt=rt->next;
                tt = tt->next;
                cout<<rt<<"=="<<tt<<endl;
               
            }
             if(rt==tt)return true;
        }
       return false;
        }
};