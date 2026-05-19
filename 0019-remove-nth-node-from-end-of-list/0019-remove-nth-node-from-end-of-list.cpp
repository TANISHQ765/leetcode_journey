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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to simplify edge cases (like removing the head)
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move the fast pointer so that there is a gap of n nodes between fast and slow
        // We go n + 1 steps so slow lands exactly BEFORE the node to be deleted
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both pointers together until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // slow->next is the node to be deleted
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Clean up memory
        delete nodeToDelete;
        
        // The real head is dummy->next
        ListNode* newHead = dummy->next;
        delete dummy; 
        
        return newHead;
    }
};