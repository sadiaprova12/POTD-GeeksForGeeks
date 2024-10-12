class Solution {
  public:
    void deleteAlt(struct Node *head) {
        //code here
        if (!head) return;

        Node* current = head;
        
        while (current && current->next) {
            Node* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            delete nodeToDelete; 
            current = current->next;
        }
    }
};