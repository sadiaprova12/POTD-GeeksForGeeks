class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        if (!head) return NULL;

        // Step 1: Insert clone nodes in between original nodes
        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->data);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // Step 2: Copy random pointers for the cloned nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next; // Move to the next original node
        }

        // Step 3: Restore the original list and extract the cloned list
        curr = head;
        Node* cloneHead = head->next;
        Node* cloneCurr = cloneHead;

        while (curr) {
            curr->next = curr->next->next; // Restore original list
            if (cloneCurr->next) {
                cloneCurr->next = cloneCurr->next->next; // Extract clone list
            }
            curr = curr->next;
            cloneCurr = cloneCurr->next;
        }

        return cloneHead;
    }
};
