class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if (!head || !head->next) return; // If the list is empty or has only one node.

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect the loop using Floyd's cycle detection algorithm.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Loop detected
                break;
            }
        }

        // If no loop exists, return
        if (slow != fast) return;

        // Step 2: Find the start of the loop
        slow = head;
        if (slow == fast) {
            // Special case: Loop starts at the head
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            // General case
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Break the loop
        fast->next = NULL;
    }
};
LRU Cache