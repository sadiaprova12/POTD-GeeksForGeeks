class Solution {
  public:
    int count(struct Node* head, int key) {
        int count = 0;
        Node* current = head;
        
        while (current != NULL) {
            if (current->data == key) {
                count++;
            }
            current = current->next; // Move to the next node
        }
        
        return count;
    }
};