class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* prev = new ListNode(-1);
        prev->next = head;

        ListNode* curr = prev;
        ListNode* temp = head;

        while(temp != NULL)
        {
            if(temp->val == val)
            {
                curr->next = temp->next;
            }
            else
            {
                curr = temp;
            }

            temp = temp->next;
        }

        return prev->next;
    }
};