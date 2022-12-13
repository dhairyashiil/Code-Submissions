/*
- To delete one node from linked list we should actually present on previous node of the node we want to delete
- But here they had given us the node they want to delete, not the previous node
- so we swapped the value stored in that node and the next node
*/

class Solution {
public:

    void deleteNode(ListNode* node) {
        
        swap(node->val, node->next->val);
        ListNode* toDelete = node->next;

        if(node->next->next!=NULL) node->next = node->next->next;
        
        else node->next = NULL;

        delete toDelete;
    }
};
