class Solution {
    public:
      Node* mergeKLists(vector<Node*>& arr) {
          priority_queue<Node*, vector<Node*>, compare> minHeap;
          
          // Push the head of each linked list into the heap
          for (Node* list : arr) {
              if (list) minHeap.push(list);
          }
          
          Node* dummy = new Node(0); // Dummy node for the merged list
          Node* tail = dummy; // Pointer to track the last node in the merged list
          
          while (!minHeap.empty()) {
              Node* top = minHeap.top();
              minHeap.pop();
              
              tail->next = top;
              tail = tail->next; // Move tail forward
              
              if (top->next) minHeap.push(top->next); // Push the next node into heap
          }
          
          return dummy->next; // Return merged linked list head
      }
  };
  