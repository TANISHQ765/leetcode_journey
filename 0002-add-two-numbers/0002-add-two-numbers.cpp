class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to act as the starting point of the result list
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        // Traverse both lists until both are empty and there is no remaining carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get values from the current nodes, or 0 if the list has ended
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum and the new carry
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            // Create a new node with the digit part of the sum (sum % 10)
            current->next = new ListNode(sum % 10);
            current = current->next;

            // Move to the next nodes in l1 and l2 if they exist
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Return the actual head (ignoring the dummy node)
        ListNode* result = dummyHead->next;
        delete dummyHead; // Clean up memory for the dummy node
        return result;
    }
};