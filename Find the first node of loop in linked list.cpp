class Solution {
  public:
    // Function to find the first node of the loop in the linked list.
    Node* findFirstNode(Node* head) {
        if (!head || !head->next) return NULL; // If list is empty or has only one node.

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect if a loop exists using Floyd's cycle detection.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // Loop detected
            if (slow == fast) {
                // Step 2: Find the starting node of the loop.
                slow = head; // Reset slow to head.
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // The starting node of the loop.
            }
        }

        // If no loop exists
        return NULL;
    }
};
