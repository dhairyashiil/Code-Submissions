class Solution {
public:

    ListNode* middleNode(ListNode* head) {

        ListNode* fast = head, slow = head;

        // In 'while' loop :
        // 1 : until last node position (Given Example 1)
        // 2 : until last node doesnt exist position (Given Example 2)
        while(fast!=NULL && fast->next!=NULL) { 
            fast = fast->next->next; // Increment by 2 steps
            slow = slow->next; // Increment by 1 step
        }

        // when fast is at end of the linked list, slow is at middle
        return slow;
    }

};
