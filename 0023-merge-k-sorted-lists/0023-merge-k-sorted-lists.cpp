using namespace std;

// REMOVE OR COMMENT OUT THE LISTNODE STRUCT DEFINITION
// LeetCode already defines it behind the scenes!

class Solution {
public:
    // Custom comparator for the min-heap to sort ListNodes by their values
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Greater-than creates a min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        for (ListNode* root : lists) {
            if (root != nullptr) {
                minHeap.push(root);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();

            tail->next = top;
            tail = tail->next;

            if (top->next != nullptr) {
                minHeap.push(top->next);
            }
        }

        ListNode* result = dummy->next;
        delete dummy; 
        return result;
    }
};