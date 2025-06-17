// merge_k_sorted_lists.cpp

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Comparator class for min-heap based on ListNode values
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap: smaller value comes first
    }
};

class Solution {
public:
    // Merges K sorted linked lists into one sorted list
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();
        if (k == 0) return NULL;

        // Push the head of each list into the heap
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL; // Head of the merged list
        ListNode* tail = NULL; // Tail to keep adding nodes

        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();

            if (top->next != NULL) {
                minHeap.push(top->next); // Push next node from same list
            }

            if (head == NULL) {
                head = top;
                tail = top;
            } else {
                tail->next = top;
                tail = top;
            }
        }

        return head;
    }
};

// Optional: Helper functions to test and print linked lists
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Optional: Example usage (can be removed for LeetCode submission)
int main() {
    // Create sample sorted linked lists:
    ListNode* a = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* b = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* c = new ListNode(2, new ListNode(6));

    vector<ListNode*> lists = {a, b, c};

    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
