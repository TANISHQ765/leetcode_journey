/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: if the list is empty or has only one node, no swapping needed.
        if (!head || !head->next) {
            return head;
        }
        
        // Dummy node to help easily manage head pointer rewiring
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        
        // Ensure there is a pair available to swap
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Start the rewiring process
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move prev forward to the end of the swapped pair
            prev = first;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dynamically allocated dummy node
        return newHead;
    }
};