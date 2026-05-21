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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. Create a dummy node to seamlessly start the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // 2. Traverse both lists until one runs out
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1; // Link the smaller node
                list1 = list1->next; // Move forward in list1
            } else {
                tail->next = list2; // Link the smaller node
                list2 = list2->next; // Move forward in list2
            }
            tail = tail->next; // Move the tail pointer forward
        }
        
        // 3. Append the remaining nodes of whichever list isn't empty
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        // 4. The actual head of the merged list is right after the dummy node
        return dummy.next;
    }
};