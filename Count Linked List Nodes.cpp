class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        //code here
        int count = 0;        
        Node* current = head; 

        while (current != NULL) {
            count++;           
            current = current->next; 
        }

        return count; 
    }
};