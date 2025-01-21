class Solution {
  public:
    // Function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    // Function to remove leading zeros from a linked list
    Node* removeLeadingZeros(Node* head) {
        while (head && head->data == 0) {
            Node* temp = head;
            head = head->next;
            delete temp; // Free memory of the removed node
        }
        return head ? head : new Node(0); // Ensure at least one zero remains
    }

    // Function to add two linked lists
    Node* addTwoLists(Node* num1, Node* num2) {
        // Reverse both lists
        num1 = reverseList(num1);
        num2 = reverseList(num2);

        Node* dummy = new Node(0); // Dummy node for the result list
        Node* tail = dummy;
        int carry = 0;

        // Add corresponding digits from both lists
        while (num1 || num2 || carry) {
            int sum = carry;
            if (num1) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2) {
                sum += num2->data;
                num2 = num2->next;
            }
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }

        // Reverse the result list and remove leading zeros
        return removeLeadingZeros(reverseList(dummy->next));
    }
};
