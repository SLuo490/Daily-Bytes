/*
This question is asked by Amazon. Given a non-empty linked list, return the middle node of the list. If the linked list contains an even number of elements, return the node closer to the end.
Ex: Given the following linked lists...

1->2->3->null, return 2
1->2->3->4->null, return 3
1->null, return 1
*/

#include <iostream> 

using namespace std; 

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head) {
  ListNode* fast = head; 
  ListNode* slow = head; 

  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next; 
    slow = slow->next; 
  }

  return slow; 
}

int main() {
  return 0;
}