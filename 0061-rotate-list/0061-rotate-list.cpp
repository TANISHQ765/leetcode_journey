class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge case: if the list is empty or has only one node
        if (!head || !head->next || k == 0) {
            return head;
        }
        
        // Step 1: Compute the length of the list and find the tail node
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        // Step 2: Handle cases where k is greater than or equal to length
        k = k % length;
        if (k == 0) {
            return head; // No rotation needed
        }
        
        // Step 3: Make the list circular
        tail->next = head;
        
        // Step 4: Find the new tail node (at position length - k)
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }
        
        // Step 5: Set the new head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};