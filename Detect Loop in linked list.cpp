class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        if (!head || !head->next) return false; // If list is empty or has only one node, no loop possible.

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;         // Move slow pointer by 1 step.
            fast = fast->next->next;  // Move fast pointer by 2 steps.

            if (slow == fast) {
                return true; // Loop detected.
            }
        }

        return false; // No loop detected.
    }
};
