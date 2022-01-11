/*
This question is asked by Apple. Given a potentially cyclical linked list where each value is unique, return the node at which the cycle starts. If the list does not contain a cycle, return null.

Ex: Given the following linked lists...

1->2->3, return null
1->2->3->4->5->2 (5 points back to 2), return a reference to the node containing 2
1->9->3->7->7 (7 points to itself), return a reference to the node containing 7
*/

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* intersection(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return slow;
    }
  }
  return nullptr;
}

ListNode* detectCycle(ListNode* head) {
  if (!head) return nullptr;

  ListNode* ptr = head;
  ListNode* ptr2 = intersection(head);

  if (ptr2 == nullptr) return nullptr;

  while (ptr != ptr2) {
    ptr = ptr->next;
    ptr2 = ptr2->next;
  }
  return ptr2;
}

int main() {
  return 0; 
}