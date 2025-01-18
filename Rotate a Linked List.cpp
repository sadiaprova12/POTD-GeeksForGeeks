class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list
        Node* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }

        // Step 2: Optimize k
        k = k % length;
        if (k == 0) return head; // No rotation needed

        // Step 3: Make the list circular temporarily
        current->next = head;

        // Step 4: Find the new head and new tail after k left rotations
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }
        Node* newHead = newTail->next;

        // Step 5: Break the loop
        newTail->next = NULL;

        return newHead;
    }
};
