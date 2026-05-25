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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node helps handle head changes seamlessly
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;
        ListNode* curr = head;

        while (curr) {
            // 1. Check if there are at least k nodes left to reverse
            ListNode* groupEnd = prevGroupEnd;
            for (int i = 0; i < k; ++i) {
                groupEnd = groupEnd->next;
                if (!groupEnd) {
                    // Less than k nodes left, leave them as they are
                    ListNode* result = dummy->next;
                    delete dummy;
                    return result;
                }
            }

            // Keep track of the node starting the next group
            ListNode* nextGroupStart = groupEnd->next;

            // 2. Reverse the current k nodes
            ListNode* prev = nextGroupStart; // Pointing to next group connects the reversed tail to the rest of the list
            ListNode* nodeToReverse = curr;
            
            for (int i = 0; i < k; ++i) {
                ListNode* nextNode = nodeToReverse->next;
                nodeToReverse->next = prev;
                prev = nodeToReverse;
                nodeToReverse = nextNode;
            }

            // 3. Connect the previous group's end to the new head of this reversed group
            ListNode* tempTail = prevGroupEnd->next; // The old head becomes the new tail
            prevGroupEnd->next = groupEnd;
            
            // Move pointers forward for the next iteration
            prevGroupEnd = tempTail;
            curr = nextGroupStart;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};